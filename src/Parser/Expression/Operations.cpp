#include "Operations.h"
#include "../../Columns/Field/BoolField.h"
#include "../../Columns/Field/FieldsCreator.h"
#include "Expression.h"
using namespace std;

namespace Parser {
EValue Operations::Op(operator_type_t op, ExprNode* expr1, ExprNode* expr2, Columns::TuplePtr tuple, Executor::ExecutorContextPtr context)
{
    EValue ret = move(Expression::Eval(expr1, tuple, context));
    EValue right;
     /// We consider short-cut optimize OR AND
    if (op == OPERATOR_OR && dynamic_cast<Columns::BoolField*>(ret.get())->GetData()) {
        return ret;
    }
    if (op == OPERATOR_AND && !dynamic_cast<Columns::BoolField*>(ret.get())->GetData()) {
        return ret;
    }
    
    /// Then we do a EVal
    right = move(Expression::Eval(expr2, tuple, context));
    if (IsOpCompared(op)) {
        bool compare = ret->Compare(op, right.get());
        Columns::BoolFieldPtr result = move(Columns::FieldsCreator::CreateBoolField());
        result->SetData(compare);
        ret = move(result);
    } else {
        ret->UpdateWithOp(op, right.get());
    }
    return ret;
}

EValue Operations::Op(operator_type_t op, ExprNode* expr, Columns::TuplePtr tuple, Executor::ExecutorContextPtr context)
{
    EValue ret = move(Expression::Eval(expr, tuple, context));
    if (IsOpQuery(op)) {
        bool compare = ret->Query(op);
        Columns::BoolFieldPtr result = Columns::FieldsCreator::CreateBoolField(compare);
        ret = move(result);
    } else {
        ret->UpdateWithOp(op);
    }
    return ret;
}

bool Operations::IsIn(const Columns::Field* field, ExprNodeList* lists) 
{
    bool isIn = false;
    if (lists == nullptr) {
        return isIn;
    }
    for (int i = 0; i < lists->size(); ++i) {
        ExprNode* expr = lists->at(i);
        EValue val = move(Expression::EvalLeafNode(expr, nullptr, nullptr));
        if (field->Compare(OPERATOR_EQ, val.get())) {
            isIn = true;
            break;
        }
    }
    return isIn;
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

bool Operations::IsOpCompared(operator_type_t op) 
{
    return OPERATOR_EQ 
        || OPERATOR_GEQ
        || OPERATOR_GT
        || OPERATOR_LEQ
        || OPERATOR_LT
        || OPERATOR_LIKE
        ;
}

bool Operations::IsOpQuery(operator_type_t op)
{
    return OPERATOR_ISNULL
        || OPERATOR_NOTNULL
        ;
}
}