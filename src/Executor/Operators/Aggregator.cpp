#include "Aggregator.h"

using namespace std;
namespace Executor {

Aggregator::Aggregator(const string& fieldName, Parser::operator_type_t aggOp)
    : fieldName(fieldName)
    , aggOp(aggOp)
{
}

int Aggregator::GetFieldNo() const 
{
    return fieldNo;
}

void Aggregator::SetFieldNo(int no)  
{   
    fieldNo = no;
}
}

