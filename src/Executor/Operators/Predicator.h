#pragma once
#include "defs.h"
#include "../../Parser/ExprNode.h"
#include "../../Columns/Field/Field.h"
#include "../../Columns/Tuple.h"
namespace Executor {

class Predicator
{
private:
    /* data */
    Parser::ExprNodeList* conds;
    
public:
    Predicator(/* args */) {};
    ~Predicator();
    Predicator(Parser::ExprNode* cond);
    Predicator(Parser::ExprNodeList* conds);
    PredicatorPtr Clone() const;

public:
    void Add(Parser::ExprNode* cond);
    bool Predicate(Columns::TuplePtr tuple);
    Parser::ExprNodeList* Get();
    Plan::FieldNames GetColumnsRef() const;
    std::string ToString() const;
};

}