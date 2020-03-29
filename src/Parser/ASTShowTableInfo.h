#pragma once
#include "defs.h"
#include "IASTNotNeedPlan.h"

namespace Parser {

class ASTShowTableInfo : public IASTNotNeedPlan
{
public:
    /* data */
    char *table;

public:
    ASTShowTableInfo(/* args */) {}
    ~ASTShowTableInfo() {}
    std::string ToString() const;
    bool IsWriteSQL() const;
    std::vector<std::string> GetTablesRef() const;

};

}