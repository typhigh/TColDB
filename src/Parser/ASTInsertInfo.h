#pragma once
#include"defs.h"
#include "IAST.h"
#include <vector>

namespace Parser {

class ASTInsertInfo : public IAST {
public:
	virtual ~ASTInsertInfo() {}
    ASTInsertInfo() {}
    virtual std::string ToString() const override; 

public:
    char* table;
	ColumnRefList* columns;
    ASTExprNodeList* values;

} ;
}