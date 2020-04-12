#include "Aggregator.h"

using namespace std;
namespace Executor {

std::string Aggregator::ToString(const std::string& prefix) const 
{
    string ret;
    for (size_t i = 0; i < fieldNames.size(); ++i) {
        ret += prefix + fieldNames[i] + " " + Parser::ToString(aggOps[i]) + "\n";
    }
    return ret;
}

void Aggregator::Add(const string& fieldName, Parser::operator_type_t aggOp)
{
    fieldNames.push_back(fieldName);
    aggOps.push_back(aggOp);
}

Plan::FieldNames Aggregator::GetColumnsRef() const 
{
    return fieldNames;
}

}

