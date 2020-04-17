#pragma once
#include "../../Columns/Field/Field.h"
#include "Expression.h"
namespace Parser {

class Operations
{
/// Operation func
public:
    static EValue Op(operator_type_t op, ExprNode* expr1, ExprNode* expr2, Columns::TuplePtr, Executor::ExecutorContextPtr context);
    static EValue Op(operator_type_t op, ExprNode* expr, Columns::TuplePtr, Executor::ExecutorContextPtr context);
    static bool IsIn(const Columns::Field* field, ExprNodeList* lists);

/// Operation self
public:
    static std::string ToString(operator_type_t op);
    static bool IsOpCompared(operator_type_t op);
    static bool IsOpQuery(operator_type_t op);
};

}
