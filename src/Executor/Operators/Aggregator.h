#pragma once
#include "../Parser/defs.h"
#include <memory>
namespace Executor {

class Aggregator
{
private:
    std::string fieldName;
    Parser::operator_type_t aggOp;
    int fieldNo;

public:
    Aggregator(){}
    Aggregator(const std::string& fieldName, Parser::operator_type_t aggOp);
    ~Aggregator() {};
public:
    int GetFieldNo() const;
    void SetFieldNo(int no);
};

using AggregatorPtr = std::shared_ptr<Aggregator>;
} 