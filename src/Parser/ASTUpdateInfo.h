#pragma once
#include "defs.h"
#include "IAST.h"
namespace Parser {

class ASTUpdateInfo : public IAST
{
public:
	char *table;
	ColumnRef *column_ref;
	ASTExprNode *where, *value;

public:
    virtual std::string ToString() const override;
};

}