#pragma once
#include "defs.h"
#include "FieldDef.h"
#include "TableConstraint.h"
#include "IASTNotNeedPlan.h"
#include "../Plan/Plan.h"
#include <vector>

namespace Parser {

class ASTCreateInfo : public IASTNotNeedPlan
{
public:
	char* name = nullptr;
	std::vector<FieldDef*>* fields = nullptr;
	std::vector<TableConstraint*>* constraints = nullptr;

public:
	~ASTCreateInfo();
	ASTCreateInfo() {}

public:
	std::string ToString() const;
	bool IsWriteSQL() const;
    std::vector<std::string> GetTablesRef() const;
	void Execute(Executor::ExecutorContextPtr context) const;
};

using ASTCreateInfoPtr = std::shared_ptr<ASTCreateInfo>;
}