#pragma once
#include "../ExprNode.h"

namespace Parser {

class Expression
{
public:
    static ExprNode* Copy(ExprNode* expr);
    static ExprNodeList* Copy(ExprNodeList* exprs);
};


}