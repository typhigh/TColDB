#pragma once
#include "defs.h"
#include "FieldDef.h"
#include "IAST.h"
#include "../Plan/Plan.h"
#include <vector>

namespace Parser {

class ASTCreateInfo : public IAST 
{
public:
	char* name;
	std::vector<FieldDef*>* fields;
	std::vector<TableConstraint*>* constraints;

public:
	virtual ~ASTCreateInfo() {}
	ASTCreateInfo() {}
	std::string ToString() const;
	Plan::PlanPtr MakePlan() const;
	bool IsWriteSQL() const;
    std::vector<std::string> GetTablesRef() const;

};

using ASTCreateInfoPtr = std::shared_ptr<ASTCreateInfo>;
}