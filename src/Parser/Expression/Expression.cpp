#include "Expression.h"
#include "Operations.h"
#include "../ASTCreator.h"
#include "../../Utils/StringUtils.h"
#include "../../Columns/Field/BoolField.h"
#include "../../Columns/Field/FieldsCreator.h"
#include <cstring>

using namespace std;

namespace Parser {

ExprNode* Expression::Copy(const ExprNode* expr) 
{
    if (expr == nullptr) {
        return nullptr;
    }
    
    /// Do a light copy first
    ExprNode* ret = ASTCreator::MakeExprNode();
    ret->op = expr->op;
    ret->term_type = expr->term_type;
    if (expr->constVal) {
        ret->constVal = expr->constVal->Clone();
    }
    
    if (IsLeafNode(expr)) {
        /// Single (Leaf) node without child
        switch (expr->term_type)
        {
        case TERM_COLUMN_REF:
            ret->column_ref = expr->column_ref->Clone();
            break;
        case TERM_LITERAL_LIST:
            ret->literal_list = Copy(expr->literal_list);
            break;
        case TERM_DATE:
        case TERM_STRING:
            ret->val_s = Utils::CopyCStringFromCString(expr->val_s);
            break;
        case TERM_BOOL:
            ret->val_b = expr->val_b;
            break;
        case TERM_FLOAT:
            ret->val_f = expr->val_f;
            break;
        case TERM_INT:
            ret->val_i = expr->val_i;
            break;
        default:
            break;
        }
        return ret;
    }

    if (IsUnary(expr)) {
        /// Single-Op
        ret->left = Copy(expr->left);
    } else {
        /// Binary-Op
        ret->left = Copy(expr->left);
        ret->right = Copy(expr->right);
    }
    return ret;
}

ExprNodeList* Expression::Copy(const ExprNodeList* exprs)
{
    ExprNodeList* ret = new ExprNodeList();
    for (ExprNode* expr: *exprs) {
        ret->push_back(Copy(expr));
    }
    return ret;
}

void Expression::Free(ExprNode* expr) 
{
    if (expr == nullptr) {
        return ;
    }
    
    /// Single (Leaf) node without child
    if (IsLeafNode(expr)) {
        switch (expr->term_type)
        {
        case TERM_COLUMN_REF:
            delete expr->column_ref;
            /* code */
            break;
        case TERM_DATE:
        case TERM_STRING:
            delete expr->val_s;
            break;
        case TERM_LITERAL_LIST:
            Free(expr->literal_list);
            break;
        default:
            break;
        }
        ASTCreator::FreeExprNode(expr);
        return;
    }

    /// No matter Unary or Binary
    Free(expr->left);
    Free(expr->right);
    ASTCreator::FreeExprNode(expr);
}

void Expression::Free(ExprNodeList* exprs) 
{
    if (exprs == nullptr) {
        return;
    }

    for (size_t i = 0; i < exprs->size(); ++i) {
        Free(exprs->at(i));
    }
    delete exprs;
}

bool Expression::IsAggregate(const ExprNode* expr) 
{
    return expr->op == OPERATOR_COUNT
        || expr->op == OPERATOR_SUM
		|| expr->op == OPERATOR_AVG
		|| expr->op == OPERATOR_MIN
		|| expr->op == OPERATOR_MAX;
}

bool Expression::IsAggregate(const ExprNodeList* exprs) 
{
    for (const ExprNode* expr: *exprs) {
        if (IsAggregate(expr)) return true;
    }
    return false;
}

bool Expression::IsColumnRef(const ExprNode* expr)
{
    return expr->op == OPERATOR_NONE
        && expr->term_type == TERM_COLUMN_REF;
}

bool Expression::IsLeafNode(const ExprNode* expr) 
{
    return expr->op == OPERATOR_NONE;
}

bool Expression::IsUnary(const ExprNode* expr) 
{
    return expr->op == OPERATOR_NOT
        || expr->op == OPERATOR_NEGATE
        || expr->op == OPERATOR_NOTNULL
        || expr->op == OPERATOR_ISNULL;
}

EValue Expression::Eval(const ExprNode* expr, Columns::TuplePtr tuple) 
{
    /// We always ues ConstOptimize before EVal (except leaf node)
    /// We think if not const, we not allow tuple == nullptr
    if (IsConstVal(expr))
    {
        return expr->constVal->Clone();
    }

    if (expr == nullptr) {
        return nullptr;
    }

    if (IsLeafNode(expr)) {
        return EvalLeafNode(expr, tuple);
    }

    if (tuple == nullptr) {
        return nullptr;
    }

    /// Not LeafNode
    operator_type_t op = expr->op;

    /// Check op == in ; such as expr: "x in (1, 2, 4)"
    if (op == OPERATOR_IN) {
        EValue left = Eval(expr->left, tuple);
        bool isIn = Operations::IsIn(left.get(), expr->right->literal_list);
        return Columns::FieldsCreator::CreateBoolField(isIn);
    }
    
    /// Check unary op ; such as : - , is null, is not null
    bool isUnary = IsUnary(expr);
    if (isUnary) {
        return Operations::Op(op, expr->left, tuple);
    }

    /// Do binary op ; such as  +, -, *, /
    return Operations::Op(op, expr->left, expr->right, tuple); 
}

EValue Expression::EvalLeafNode(const ExprNode* expr, Columns::TuplePtr tuple)
{
    if (expr->constVal != nullptr) {
        return expr->constVal->Clone();
    }

    switch (expr->term_type)
    {
    case TERM_BOOL:     return Columns::FieldsCreator::CreateBoolField(expr->val_b);
    /// For executor we use varchar
    case TERM_STRING:   return Columns::FieldsCreator::CreateVarcharField(expr->val_s);
    case TERM_DATE:     return Columns::FieldsCreator::CreateDateField(expr->val_s);
    case TERM_FLOAT:    return Columns::FieldsCreator::CreateDoubleField(expr->val_f);
    case TERM_INT:      return Columns::FieldsCreator::CreateIntField(expr->val_i);
    case TERM_COLUMN_REF: 
    {
        if (tuple == nullptr) {
            return nullptr;
        }
        ColumnRef* colRef = expr->column_ref;
        if (colRef->pos > 0) {
            /*TODO*/
            return tuple->GetFieldCopy(colRef->pos);
        }
        string fieldName = colRef->GetFieldName();
        return tuple->GetFieldCopy(fieldName, colRef->pos);
    }
    default:
        LOG_ERROR("Unsupported term type in EValLeafNode");
        return nullptr;
    }
}

void Expression::ConstOptimize(ExprNode* expr) 
{
    if (expr == nullptr) {
        return ;
    }

    /// Been const yet
    if (expr->constVal != nullptr) {
        return ;
    }

    /// Consider LeafNode
    if (IsLeafNode(expr)) {
        EValue value = EvalLeafNode(expr, nullptr);
        if (value == nullptr) {
            /// This expr is not constant
            return ;
        }
        /// Is Const, we add constValue to this expr
        expr->constVal = move(value);
        return ;
    }
    
    ExprNode* left = expr->left;
    ExprNode* right = expr->right;
    operator_type_t op = expr->op;
    ConstOptimize(left);

    /// Consider Unary op
    if (IsUnary(expr)) {
        if (IsConstVal(left)) {
            expr->constVal = Operations::Op(op, left, nullptr);
        }
        return ;
    }

    // Consider In op
    if (op == OPERATOR_IN) {
        if (IsConstVal(left)) {
            bool isIn = Operations::IsIn(left->constVal.get(), right->literal_list);
            EValue value = Columns::FieldsCreator::CreateBoolField(isIn);
            expr->constVal = move(value);
        }
        return ;
    }

    // Consider Binary op
    ConstOptimize(right);
    EValue value = Operations::Op(op, left, right, nullptr);
    if (value != nullptr) {
        expr->constVal = move(value);
    }
}

bool Expression::IsConstVal(const ExprNode* expr) 
{
    return expr != nullptr && expr->constVal != nullptr;
}

FieldNames Expression::GetColumnsRef(const ExprNode* expr) 
{
    FieldNames ret;
    if (expr == nullptr) {
        return ret;
    }
    
    if (expr->op == OPERATOR_NONE) {
        if (expr->term_type == TERM_COLUMN_REF) {
            ret = {expr->column_ref->GetFieldName()};
        }
        return ret;
    }
    
    Append(ret, GetColumnsRef(expr->left));
    Append(ret, GetColumnsRef(expr->right));
    return ret;
}

FieldNames Expression::GetColumnsRef(const ExprNodeList* exprs)
{
    FieldNames ret;
    if (exprs == nullptr) {
        return ret;
    }

    for (const ExprNode* expr : *exprs) {
        Append(ret, GetColumnsRef(expr));
    }
    
    return ret;
}

void Expression::Append(FieldNames& result, const FieldNames& other)
{
    /// Use insert 
    /// TODO: use move
    result.insert(result.end(), other.begin(), other.end());
}

}