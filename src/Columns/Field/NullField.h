#pragma once
#include "Field.h"

namespace Columns {

class NullField : public Field
{
private:
    /* data */
public:
    NullField(/* args */) {}
    virtual ~NullField() {}
    Parser::FieldType_t GetType() const;
    std::string ToString() const;
    FieldPtr Clone() const;

/// Operations def
public:
    bool Compare(Parser::operator_type_t op, const Field* other) const;
    bool Query(Parser::operator_type_t op) const;

    FieldPtr Op(Parser::operator_type_t op, const Field* other) const;
    FieldPtr Op(Parser::operator_type_t op) const;

    void UpdateWithOp(Parser::operator_type_t op, const Field* other);
    void UpdateWithOp(Parser::operator_type_t op);  
};

using NullFieldPtr = std::unique_ptr<NullField, FieldDeleteFunc>;
}
