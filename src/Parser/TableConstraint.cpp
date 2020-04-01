#include "TableConstraint.h"
#include "Expression/Expression.h"
using namespace std;

namespace Parser {

TableConstraint::~TableConstraint() 
{
    delete column_ref;
    delete foreign_column_ref;
    Expression::Free(check_cond);
}

}