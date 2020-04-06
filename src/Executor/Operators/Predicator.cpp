#include "Predicator.h"
#include "../../Parser/Expression/Expression.h"
using namespace std;

namespace Executor {

Predicator::Predicator(Parser::ExprNode* cond) 
{
    conds = Parser::Expression::GetAndExprs(cond);
}

Predicator::Predicator(Parser::ExprNodeList* conds)
{
    this->conds = Parser::Expression::Copy(conds);
}

PredicatorPtr Predicator::Clone() const 
{
    return make_shared<Predicator>(conds);
}

void Predicator::Add(Parser::ExprNode* cond)
{
    if (cond == nullptr) {
        return;
    } 

    if (conds == nullptr) {
        conds = new Parser::ExprNodeList();
    } 

    conds->push_back(Parser::Expression::Copy(cond));
}

Predicator::~Predicator() 
{
    Parser::Expression::Free(conds);
}

bool Predicator::Predicate(Columns::TuplePtr tuple)
{
    /*TODO*/
    return true;
}

Plan::FieldNames Predicator::GetColumnsRef() const 
{
    return Parser::Expression::GetColumnsRef(conds);
}

}