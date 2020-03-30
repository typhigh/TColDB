#pragma once
#include "defs.h"
#include "IASTNeedPlan.h"
#include "../Plan/Plan.h"

namespace Parser {

class ASTSelectInfo : public IASTNeedPlan
{
public:
	TableFromList* tables;
	ExprNodeList* exprs;
	ExprNode* where;
	
public:
    std::string ToString() const;
	Plan::PlanPtr MakePlan(Plan::PlanContextPtr planContext) const;
	bool IsWriteSQL() const;
    std::vector<std::string> GetTablesRef() const;

};

}