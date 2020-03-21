#pragma once
#include "defs.h"
#include "IAST.h"
#include "../Plan/Plan.h"

namespace Parser {

class ASTSelectInfo : public IAST 
{
public:
	TableFromList* tables;
	ExprNodeList* exprs;
	ExprNode* where;
	
public:
    std::string ToString() const;
	Plan::PlanPtr MakePlan() const;
};

}