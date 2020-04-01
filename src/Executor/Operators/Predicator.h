#pragma once
#include "../../Parser/ExprNode.h"
#include "../../Columns/Field/Field.h"
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
    bool Predicate(Columns::FieldPtr field);
};

using PredicatorPtr = std::shared_ptr<Predicator>;
}