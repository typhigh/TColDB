#pragma once
#include "defs.h"
#include "../../Parser/ExprNode.h"
#include "../../Columns/Field/Field.h"
#include "../../Columns/Tuple.h"
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
    Predicator(Parser::ExprNodeList* conds);
    PredicatorPtr Clone() const;
    void Add(Parser::ExprNode* cond);
    bool Predicate(Columns::TuplePtr tuple);
    Plan::FieldNames GetColumnsRef() const;
};

}