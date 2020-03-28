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
    DoubleField(ValT data) : data(data) {}
    ~DoubleField() {}
    Parser::FieldType_t GetType() const;
    std::string ToString() const;
    FieldPtr Clone() const;
    ValT GetData() const;
    void SetData(ValT data);    
/// Operations def
public:
    bool Compare(Parser::operator_type_t op, const Field* other) const;
    bool Query(Parser::operator_type_t op) const;

    FieldPtr Op(Parser::operator_type_t op, const Field* other) const;
    FieldPtr Op(Parser::operator_type_t op) const;

    void UpdateWithOp(Parser::operator_type_t op, const Field* other);
    void UpdateWithOp(Parser::operator_type_t op);
};
using DoubleFieldPtr = std::unique_ptr<DoubleField, FieldDeleteFunc>;

}
