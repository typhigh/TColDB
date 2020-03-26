#pragma once
#include "Field.h"

namespace Columns {

class DoubleField : public Field
{
public:
    using ValT = float;

private:
    /* data */
    ValT data;
    
public:
    DoubleField(/* args */) {}
    ~DoubleField() {}
    bool IsType(Parser::FieldType type) const;
    std::string ToString() const;
    ValT GetData() const;
    void SetData(ValT data);    
/// Operations def
public:
    FieldPtr Op(Parser::operator_type_t op, const FieldPtr other) const;
    FieldPtr Op(Parser::operator_type_t op) const;
};
using DoubleFieldPtr = Utils::ObjectPool<DoubleField>::ObjectPtr;

}
