#pragma once 
#include "defs.h"
#include "IASTNeedPlan.h"
#include "../Plan/Plan.h"

namespace Parser {

class ASTDeleteInfo : public IASTNeedPlan
{
public:
    ASTDeleteInfo() {}
    ~ASTDeleteInfo();
    std::string ToString() const ;
    Plan::PlanPtr MakePlan(Plan::PlanContextPtr context) const;
    bool IsWriteSQL() const;
    std::vector<std::string> GetTablesRef() const;

public:
	char *table;
	ExprNode *where;
};

}