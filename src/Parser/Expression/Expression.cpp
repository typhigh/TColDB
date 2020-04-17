#include "Expression.h"
#include "Operations.h"
#include "../ASTCreator.h"
#include "../../Utils/StringUtils.h"
#include "../../Utils/VectorUtils.h"
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

ExprNodeList* Expression::GetAndExprs(const ExprNode* expr)
{
    ExprNodeList* ret = new ExprNodeList();
    GetAndExprs(expr, ret);
    return ret;
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

EValue Expression::Eval(const ExprNode* expr, Columns::TuplePtr tuple, Executor::ExecutorContextPtr context) 
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
        return EvalLeafNode(expr, tuple, context);
    }

    if (tuple == nullptr) {
        return nullptr;
    }

    /// Not LeafNode
    operator_type_t op = expr->op;

    /// Check op == in ; such as expr: "x in (1, 2, 4)"
    if (op == OPERATOR_IN) {
        EValue left = Eval(expr->left, tuple, context);
        bool isIn = Operations::IsIn(left.get(), expr->right->literal_list);
        return Columns::FieldsCreator::CreateBoolField(isIn);
    }
    
    /// Check unary op ; such as : - , is null, is not null
    bool isUnary = IsUnary(expr);
    if (isUnary) {
        return Operations::Op(op, expr->left, tuple, context);
    }

    /// Do binary op ; such as  +, -, *, /
    return Operations::Op(op, expr->left, expr->right, tuple, context); 
}

EValue Expression::EvalLeafNode(const ExprNode* expr, Columns::TuplePtr tuple, Executor::ExecutorContextPtr context)
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
            return tuple->GetFieldCopy(colRef->pos, context);
        }
        string fieldName = colRef->GetFieldName();
        return tuple->GetFieldCopy(fieldName, colRef->pos, context);
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
        EValue value = EvalLeafNode(expr, nullptr, nullptr);
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
            expr->constVal = Operations::Op(op, left, nullptr, nullptr);
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
    EValue value = Operations::Op(op, left, right, nullptr, nullptr);
    if (value != nullptr) {
        expr->constVal = move(value);
    }
}

void Expression::ConstOptimize(ExprNodeList* exprs) 
{
    if (exprs == nullptr) {
        return ;
    }

    for (ExprNode* expr : *exprs) {
        ConstOptimize(expr);
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
    
    ret = GetColumnsRef(expr->left);
    Utils::MergeVectors(ret, GetColumnsRef(expr->right));
    return ret;
}

FieldNames Expression::GetColumnsRef(const ExprNodeList* exprs)
{
    FieldNames ret;
    if (exprs == nullptr) {
        return ret;
    }

    for (const ExprNode* expr : *exprs) {
        Utils::MergeVectors(ret, GetColumnsRef(expr));
    }
    
    return ret;
}

string Expression::ToString(const string& prefix, const ExprNodeList* exprs)
{
    if (exprs == nullptr) {
        return "{}";
    }

    string ret;
    for (const ExprNode* expr: *exprs) {
        ret += prefix + ToString("", expr) + "\n";
    }

    ret = prefix + "{\n" + ret + prefix + "}\n";
    return ret;
}

string Expression::ToString(const string& prefix, const ExprNode* expr)
{
    string ret;
    if (expr == nullptr) {
        return prefix + "nullptr";
    }

    if (IsLeafNode(expr)) {
        switch (expr->term_type)
        {
        case TERM_BOOL:         return prefix + to_string(expr->val_b);
        case TERM_STRING:   
        case TERM_DATE:         return prefix + Utils::CopyStringFromCString(expr->val_s);
        case TERM_FLOAT:        return prefix + to_string(expr->val_f);
        case TERM_INT:          return prefix + to_string(expr->val_i);
        case TERM_NULL:         return prefix + "null";
        case TERM_COLUMN_REF:   return prefix + expr->column_ref->GetFieldName();
        case TERM_LITERAL_LIST:
        {
            ret = "{";
            for (size_t i = 0 ; i < expr->literal_list->size(); ++i) {
                ret += ToString("" ,expr->literal_list->at(i)) + ",";
            }
            ret += "}";
            return prefix + ret;
        }
        default:         
        {
            LOG_ERROR("unknown term type");
            return "";
        }
        }
    }

    if (IsUnary(expr)) {
        ret = Operations::ToString(expr->op) + " " + ToString("", expr->left);
        return prefix + ret;
    }
    
    ret = ToString("",expr->left) + " " + Operations::ToString(expr->op) + " " + ToString("", expr->right);
    return prefix + ret;
}

void Expression::GetAndExprs(const ExprNode* expr, ExprNodeList* exprs)
{
    if (expr == nullptr) {
        return;
    }

    if (expr->op == OPERATOR_AND) {
        GetAndExprs(expr->left, exprs);
        GetAndExprs(expr->right, exprs);
        return;
    } 

    exprs->push_back(Expression::Copy(expr));
}

}