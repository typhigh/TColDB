#pragma once
#include "IASTNotNeedPlan.h"
#include "defs.h"

namespace Parser {

class ASTDropTableInfo : public IASTNotNeedPlan
{
public:
    /* data */
    char* table;

public:
    ASTDropTableInfo(/* args */) {}
    ~ASTDropTableInfo();
    
    std::string ToString() const;
    bool IsWriteSQL() const;
    std::vector<std::string> GetTablesRef() const;
};

}