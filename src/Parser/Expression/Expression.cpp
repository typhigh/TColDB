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
    // Do a light copy first
    ExprNode* ret = ASTCreator::MakeExprNode();
    *ret = *expr;
    if (expr->op == OPERATOR_NONE) {
        // Single node without child
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
        default:
            break;
        }
        return ret;
    }

    if (expr->op == OPERATOR_UNARY) {
        // Single-Op
        ret->left = Copy(expr->left);
    } else {
        // Binary-Op
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
    if (expr == NULL) {
        return EValue();
    }

    if (IsLeafNode(expr)) {
        return EvalLeafNode(expr, tuple);
    }

    /// Not LeafNode
    operator_type_t op = expr->op;

    /// Check op == in ; such as expr: "x in (1, 2, 4)"
    if (op == OPERATOR_IN) {
        EValue left = Eval(expr->left, tuple);
        bool isIn = Operations::IsIn(left.get(), expr->right->literal_list, tuple);
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
        ColumnRef* colRef = expr->column_ref;
        if (colRef->pos > 0) {
            /*TODO*/
            return tuple->GetFieldCopy(colRef->pos);
        }
        string fieldName = colRef->GetFieldName();
        return tuple->GetFieldCopy(fieldName);
    }
    default:
        LOG_ERROR("Unsupported term type in EValLeafNode");
        return nullptr;
    }
}
}