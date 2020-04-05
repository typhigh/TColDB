#pragma once
#include "../../Parser/ExprNode.h"
#include "../../Columns/Field/Field.h"
#include "../../Columns/Tuple.h"
#include <memory>
namespace Executor {

class Predicator
{
public:
    /* data */
    Parser::ExprNodeList* conds;
    
public:
    Predicator(/* args */) {};
    ~Predicator();
    Predicator(Parser::ExprNode* cond);
    void Add(Parser::ExprNode* cond);
    bool Predicate(Columns::TuplePtr tuple);
    Plan::FieldNames GetColumnsRef() const;
};

using PredicatorPtr = std::shared_ptr<Predicator>;
}