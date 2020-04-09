#pragma once
#include "IASTNotNeedPlan.h"

namespace Parser {

class ASTCommit : public IASTNotNeedPlan
{
public:
    char* table = nullptr;

public:
    ASTCommit(/* args */){}
    ~ASTCommit() {}

public:
	std::string ToString() const;
	bool IsWriteSQL() const;
    std::vector<std::string> GetTablesRef() const;
	void Execute(Executor::ExecutorContextPtr context) const;
};


}