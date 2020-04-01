#include "Predicator.h"
#include "../../Parser/Expression/Expression.h"
using namespace std;

namespace Executor {

Predicator::Predicator(Parser::ExprNode* cond) 
{
    this->cond = Parser::Expression::Copy(cond);
}

Predicator::~Predicator() 
{
    Parser::Expression::Free(this->cond);
}

bool Predicator::Predicate(Columns::FieldPtr field)
{
    /*TODO*/
    return true;
}

}