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
	char* name;
	std::vector<FieldDef*>* fields;
	std::vector<TableConstraint*>* constraints;

public:
	virtual ~ASTTableDef() {}
	ASTTableDef() {}
	std::string ToString() const;
	Plan::PlanPtr MakePlan() const;
	bool IsWriteSQL() const;
    std::vector<std::string> GetTablesRef() const;

};

using ASTTableDefPtr = std::shared_ptr<ASTTableDef>;
}