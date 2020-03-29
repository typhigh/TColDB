#pragma once
#include "IASTNotNeedPlan.h"
#include "defs.h"

namespace Parser {

class ASTSetOutput : public IASTNotNeedPlan
{
public:
    /* data */
    char* path;

public:
    ASTSetOutput() {}
    ~ASTSetOutput() {}

    std::string ToString() const;
    bool IsWriteSQL() const;
    std::vector<std::string> GetTablesRef() const;
};


}