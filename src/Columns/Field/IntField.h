#pragma once
#include "Field.h"

namespace Columns {

class IntField : public Field
{
private:
    /* data */
    int data;
    
public:
    IntField(/* args */) {}
    ~IntField() {}
    bool IsType(Parser::FieldType type) const;
    std::string ToString() const;
    int GetData() const;
/// Operations def
public:
    FieldPtr Op(Parser::operator_type_t op, const FieldPtr other) const;
    FieldPtr Op(Parser::operator_type_t op) const;
};
using IntFieldPtr = std::shared_ptr<IntField>;

}
