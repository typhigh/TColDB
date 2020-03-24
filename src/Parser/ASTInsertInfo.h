#pragma once
#include"defs.h"
#include "IAST.h"
#include "../Plan/Plan.h"
#include <vector>

namespace Parser {

class ASTInsertInfo : public IAST 
{
public:
	virtual ~ASTInsertInfo() {}
    ASTInsertInfo() {}
    std::string ToString() const; 
    Plan::PlanPtr MakePlan() const;
    bool IsWriteSQL() const;
    std::vector<std::string> GetTablesRef() const;

public:
    char* table;
	ColumnRefList* columns;
    ExprNodeList* values;

};

}