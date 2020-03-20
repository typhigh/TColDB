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
public:
	char *table;
	ExprNode *where;
};

}