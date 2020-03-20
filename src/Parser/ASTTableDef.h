#pragma once
#include "defs.h"
#include "FieldDef.h"
#include "IAST.h"
#include "../Plan/Plan.h"
#include <vector>

namespace Parser {

class ASTTableDef : public IAST 
{
public:
	virtual ~ASTTableDef() {}
	ASTTableDef() {}
	std::string ToString() const;
	Plan::PlanPtr MakePlan() const;
public:
	char* name;
	std::vector<FieldDef*>* fields;
	std::vector<TableConstraint*>* constraints;
};

using ASTTableDefPtr = std::shared_ptr<ASTTableDef>;
}