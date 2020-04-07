#pragma once
#include "defs.h"
#include "IASTNotNeedPlan.h"
namespace Parser {

class ASTExit : public IASTNotNeedPlan
{
public:
    ASTExit(/* args */) {}
    ~ASTExit() {}

public:
    std::string ToString() const;
    bool IsWriteSQL() const;
    std::vector<std::string> GetTablesRef() const;
    void Execute(Executor::ExecutorContextPtr context) const;
};

}