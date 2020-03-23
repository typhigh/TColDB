#include "Expression.h"
#include "../ASTCreator.h"
#include "../../Utils/StringUtils.h"
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

}