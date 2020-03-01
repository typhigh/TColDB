/*
#pragma once
#include "IAST.h"

namespace Parser {

class ASTFieldItem : public IAST
{
private:
    char* name;
	int type;
    int width;
    int flags;
	ASTFieldItem *next;
	ASTExprNode *default_value;

public:
    IASTPtr Clone() const override;
};

using ASTFieldItemPtr = std::shared_ptr<ASTFieldItem>;
}

*/