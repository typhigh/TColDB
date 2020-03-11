#pragma once
#include "defs.h"
#include "IAST.h"

namespace Parser {

class ASTSelectInfo : public IAST 
{
public:
	ASTTableJoinInfoList* tables;
	ASTExprNodeList* exprs;
	ASTExprNode* where;
public:
    virtual std::string ToString() const override;
};

}