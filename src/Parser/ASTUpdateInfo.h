#pragma once
#include "defs.h"
#include "IASTNeedPlan.h"
#include "../Plan/Plan.h"
namespace Parser {

class ASTUpdateInfo : public IASTNeedPlan
{
public:
	char *table = nullptr;
	ColumnRef *column_ref = nullptr;
	ExprNode *where = nullptr;
	ExprNode *value = nullptr;

public:
    std::string ToString() const;
	Plan::PlanPtr MakePlan(Plan::PlanContextPtr context) const;
	bool IsWriteSQL() const;
    std::vector<std::string> GetTablesRef() const;

};

}