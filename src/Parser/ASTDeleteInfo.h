#pragma once 
#include "defs.h"
#include "IAST.h"

namespace Parser {

class ASTDeleteInfo : public IAST
{
public:
    ASTDeleteInfo() : IAST() {}
    virtual ~ASTDeleteInfo() {}
    virtual std::string ToString() const override;
public:
	char *table;
	ASTExprNode *where;
};

}