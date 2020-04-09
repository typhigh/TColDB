#pragma once
#include "defs.h"
#include "IASTNeedPlan.h"
#include "../Plan/Plan.h"

namespace Parser {

class ASTSelectInfo : public IASTNeedPlan
{
public:
	TableFromList* tables = nullptr;
	ExprNodeList* exprs = nullptr;
	ExprNode* where = nullptr;
	
public:
	ASTSelectInfo() {}
	~ASTSelectInfo();
    std::string ToString() const;
	Plan::PlanPtr MakePlan(Plan::PlanContextPtr context) const;
	bool IsWriteSQL() const;
    std::vector<std::string> GetTablesRef() const;

};

}