#pragma once
#include "defs.h"
#include "ExprNode.h"

namespace Parser {

class ASTCreator
{
public:
    static ExprNode* MakeExprNode();
};

}