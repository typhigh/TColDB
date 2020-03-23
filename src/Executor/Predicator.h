#pragma once
#include "../Parser/ExprNode.h"
#include <memory>
namespace Executor {

class Predicator
{
private:
    /* data */
    Parser::ExprNode* cond;
    
public:
    Predicator(/* args */) {};
    ~Predicator() {};
    Predicator(Parser::ExprNode* cond);
};

using PredicatorPtr = std::shared_ptr<Predicator>;
}