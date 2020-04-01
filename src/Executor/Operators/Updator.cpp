#include "Updator.h"
#include "../../Parser/Expression/Expression.h"
using namespace std;

namespace Executor {

Updator::Updator(Parser::ExprNode* value) 
{
    this->value = Parser::Expression::Copy(value);
}

Updator::~Updator()
{
    Parser::Expression::Free(value);
}

}