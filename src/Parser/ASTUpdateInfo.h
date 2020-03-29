#pragma once
#include "defs.h"
#include "IASTNeedPlan.h"
#include "../Plan/Plan.h"
namespace Parser {

class ASTUpdateInfo : public IASTNeedPlan
{
public:
	char *table;
	ColumnRef *column_ref;
	ExprNode *where, *value;

public:
    std::string ToString() const;
	Plan::PlanPtr MakePlan() const;
	bool IsWriteSQL() const;
    std::vector<std::string> GetTablesRef() const;

};

}