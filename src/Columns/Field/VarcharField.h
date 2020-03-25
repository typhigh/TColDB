#pragma once
#include "Field.h"
namespace Columns {
class VarcharField : public Field
{
private:
    /* data */
    std::string data;

public:
    VarcharField(/* args */) {}
    ~VarcharField() {}
    bool IsType(Parser::FieldType type) const;
    std::string ToString() const;
    std::string GetData() const;

/// Operations def
public:
    FieldPtr Op(Parser::operator_type_t op, const FieldPtr other) const;
    FieldPtr Op(Parser::operator_type_t op) const;
};
using VarcharFieldPtr = std::shared_ptr<VarcharField>;

}