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
    void SetData(const std::string& data);

/// Operations def
public:
    FieldPtr Op(Parser::operator_type_t op, const FieldPtr other) const;
    FieldPtr Op(Parser::operator_type_t op) const;
};

using VarcharFieldPtr = Utils::ObjectPool<VarcharField>::ObjectPtr;

}