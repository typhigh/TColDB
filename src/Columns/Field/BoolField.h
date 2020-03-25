#pragma once
#include "Field.h"

namespace Columns {

class BoolField : public Field
{
private:
    /* data */
    bool data;
    
public:
    BoolField(/* args */) {}
    ~BoolField() {}
    bool IsType(Parser::FieldType type) const;
    std::string ToString() const;
    bool GetData() const;

/// Operations def
public:
    FieldPtr Op(Parser::operator_type_t op, const FieldPtr other) const;
    FieldPtr Op(Parser::operator_type_t op) const;
};

using BoolFieldPtr = std::shared_ptr<BoolField>;
}
