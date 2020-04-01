#include "FieldDef.h"
#include "Expression/Expression.h"
using namespace std;

namespace Parser {

FieldDef::~FieldDef() 
{
    delete name;
    Expression::Free(default_value);
}

}