#pragma once
#include "../../Parser/ExprNode.h"
#include <memory>
namespace Executor {

class Predicator
{
public:
    /* data */
    Parser::ExprNode* cond;
    
public:
    Predicator(/* args */) {};
    ~Predicator();
    Predicator(Parser::ExprNode* cond);


};

using PredicatorPtr = std::shared_ptr<Predicator>;
}