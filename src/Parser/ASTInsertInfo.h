#pragma once
#include"defs.h"
#include "IASTNotNeedPlan.h"
#include "../Plan/Plan.h"
#include <vector>

namespace Parser {

class ASTInsertInfo : public IASTNotNeedPlan
{
public:
    char* table;
	ColumnRefList* columns;
    ExprNodeList* values;

public:
	virtual ~ASTInsertInfo() {}
    ASTInsertInfo() {}
    std::string ToString() const; 
    bool IsWriteSQL() const;
    std::vector<std::string> GetTablesRef() const;
    void Execute(Executor::ExecutorContextPtr context) const;
};

}