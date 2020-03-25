#pragma once
#include <memory>
#include "../../Parser/FieldType.h"
#include "../../Parser/defs.h"
namespace Columns {
class Field
{
private:
    /* data */
public:
    Field(/* args */) {}
    virtual ~Field() {}
    virtual bool IsType(Parser::FieldType type) const = 0;
    virtual std::string ToString() const = 0;

/// Operation between this and another field
public:
    virtual FieldPtr Op(Parser::operator_type_t op, const FieldPtr& other) const = 0;
    virtual FieldPtr Op(Parser::operator_type_t op) const = 0;
};

using FieldPtr = std::shared_ptr<Field>;
}