#include "Aggregator.h"

using namespace std;
namespace Executor {

void Aggregator::Add(const string& fieldName, Parser::operator_type_t aggOp)
{
    fieldNames.push_back(fieldName);
    aggOps.push_back(aggOp);
}

}

