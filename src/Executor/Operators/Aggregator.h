#pragma once
#include "../../Parser/defs.h"
#include "../../Plan/Plan.h"
#include <memory>
namespace Executor {

class Aggregator
{
private:
    std::vector<std::string> fieldNames;
    std::vector<Parser::operator_type_t> aggOps;
    std::vector<int> fieldsNo;

public:
    Aggregator(){}
    ~Aggregator() {};

public:
    void Add(const std::string& fieldName, Parser::operator_type_t aggOp);
    void SetFieldsNo(size_t kth, int fieldNo);
    int GetFieldsNo(size_t kth) const;
    Plan::FieldNames GetColumnsRef() const;
};

using AggregatorPtr = std::shared_ptr<Aggregator>;
} 