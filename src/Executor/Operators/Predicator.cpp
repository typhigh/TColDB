#include "Predicator.h"
#include "../../Parser/Expression/Expression.h"
using namespace std;

namespace Executor {

Predicator::Predicator(Parser::ExprNode* cond) 
{
    conds = Parser::Expression::GetAndExprs(cond);
}

Predicator::~Predicator() 
{
    Parser::Expression::Free(conds);
}

bool Predicator::Predicate(Columns::FieldPtr field)
{
    /*TODO*/
    return true;
}

Plan::FieldNames Predicator::GetColumnsRef() const 
{
    return Parser::Expression::GetColumnsRef(conds);
}

}