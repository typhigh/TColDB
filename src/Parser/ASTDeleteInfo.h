#pragma once 
#include "defs.h"
#include "IASTNeedPlan.h"
#include "../Plan/Plan.h"

namespace Parser {

class ASTDeleteInfo : public IASTNeedPlan
{
public:
    ASTDeleteInfo() {}
    virtual ~ASTDeleteInfo() {}
    std::string ToString() const ;
    Plan::PlanPtr MakePlan() const;
    bool IsWriteSQL() const;
    std::vector<std::string> GetTablesRef() const;

public:
	char *table;
	ExprNode *where;
};

}