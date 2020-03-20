#pragma once
#include "defs.h"
#include "IAST.h"
#include "../Plan/Plan.h"

namespace Parser {

class ASTTableJoinInfo : public IAST
{
public:
	table_join_type_t join_type;
	char *table, *join_table, *alias;
	ExprNode *cond;

public:
    std::string ToString() const;
	Plan::PlanPtr MakePlan() const;
};

}