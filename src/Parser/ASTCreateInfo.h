#pragma once
#include "defs.h"
#include "FieldDef.h"
#include "IASTNotNeedPlan.h"
#include "../Plan/Plan.h"
#include <vector>

namespace Parser {

class ASTCreateInfo : public IASTNotNeedPlan
{
public:
	char* name;
	std::vector<FieldDef*>* fields;
	std::vector<TableConstraint*>* constraints;

public:
	~ASTCreateInfo();
	ASTCreateInfo() {}

public:
	std::string ToString() const;
	bool IsWriteSQL() const;
    std::vector<std::string> GetTablesRef() const;
};

using ASTCreateInfoPtr = std::shared_ptr<ASTCreateInfo>;
}