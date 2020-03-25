#pragma once
#include "../../Columns/Field/Field.h"
#include "Expression.h"
namespace Parser {

class Operations
{
/// Operation func
public:
    static EValue Op(operator_type_t op, ExprNode* expr1, ExprNode* expr2, Columns::TuplePtr);
    static EValue Op(operator_type_t op, ExprNode* expr, Columns::TuplePtr);
    static EValue In(ExprNode* expr, ExprNodeList* lists, Columns::TuplePtr);

/// Operation self
public:
    static std::string ToString(operator_type_t op);
};

}
