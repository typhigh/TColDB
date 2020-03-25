#include "Operations.h"
#include "../../Columns/Field/BoolField.h"
using namespace std;

namespace Parser {
EValue Operations::Op(operator_type_t op, ExprNode* expr1, ExprNode* expr2, Columns::TuplePtr)
{
    /// We consider short-cut optimize OR AND
    EValue ret;
    EValue left;
    EValue eright;
    if (op == OPERATOR_OR) {
        left = Expression::Eval(expr1);
        if (!left->IsType(FieldType(FIELD_TYPE_BOOL))) {
            LOG_ERROR("expected a bool EValue");
            return EValue();
        }  
        Columns::BoolFieldPtr left_ = left;

    }
}

EValue Operations::Op(operator_type_t op, ExprNode* expr, Columns::TuplePtr)
{

}

EValue Operations::In(ExprNode* expr, ExprNodeList* lists, Columns::TuplePtr) 
{

}

string Operations::ToString(operator_type_t op) 
{
    switch (op)
    {
    case OPERATOR_ADD:      return "OPERATOR_ADD";
    case OPERATOR_AND:      return "OPERATOR_AND";
    case OPERATOR_AVG:      return "OPERATOR_AVG";
    case OPERATOR_COUNT :   return "OPERATOR_COUNT";
    case OPERATOR_DIV:      return "OPERATOR_DIV";
    case OPERATOR_EQ:       return "OPERATOR_EQ";
    case OPERATOR_GEQ:      return "OPERATOR_GEQ";
    case OPERATOR_GT:       return "OPERATOR_GT";
    case OPERATOR_IN:       return "OPERATOR_IN";
    case OPERATOR_ISNULL:   return "OPERATOR_ISNULL";
    case OPERATOR_LEQ:      return "OPERATOR_LEQ";
    case OPERATOR_LIKE:     return "OPERATOR_LIKE";
    case OPERATOR_LT:       return "OPERATOR_LT";
    case OPERATOR_MAX:      return "OPERATOR_MAX";
    case OPERATOR_MIN:      return "OPERATOR_MIN";
    case OPERATOR_MINUS:    return "OPERATOR_MINUS";
    case OPERATOR_MUL:      return "OPERATOR_MUL";
    case OPERATOR_NEGATE:   return "OPERATOR_NEGATE";
    case OPERATOR_NEQ:      return "OPERATOR_NEQ";
    case OPERATOR_NONE:     return "OPERATOR_NONE";
    case OPERATOR_NOT:      return "OPERATOR_NOT";
    case OPERATOR_NOTNULL:  return "OPERATOR_NOTNULL";
    case OPERATOR_OR:       return "OPERATOR_OR";
    case OPERATOR_SUM:      return "OPERATOR_SUM";
    default:                return "UNKNOWN_OPTYPE";
    }
}
}