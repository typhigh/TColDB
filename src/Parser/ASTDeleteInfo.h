#pragma once 
#include "defs.h"
#include "IAST.h"
#include "../Plan/Plan.h"

namespace Parser {

class ASTDeleteInfo : public IAST
{
public:
    ASTDeleteInfo() : IAST() {}
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