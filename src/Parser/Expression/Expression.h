#pragma once
#include "../ExprNode.h"

namespace Parser {

class Expression
{
public:
    static ExprNode* Copy(const ExprNode* expr);
    static ExprNodeList* Copy(const ExprNodeList* exprs);
    static bool IsAggregate(const ExprNode* expr);
    static bool IsAggregate(const ExprNodeList* epxrs);
    static bool IsColumnRef(const ExprNode* expr);

};


}