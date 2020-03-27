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
    IntField(int data) : data(data) {}
    ~IntField() {}
    Parser::FieldType_t GetType() const;
    std::string ToString() const;
    FieldPtr Clone() const = 0;
    int GetData() const;
    void SetData(int data);
/// Operations def
public:
    bool Compare(Parser::operator_type_t op, const Field* other) const;
    bool Query(Parser::operator_type_t op) const;
    
    FieldPtr Op(Parser::operator_type_t op, const Field* other) const;
    FieldPtr Op(Parser::operator_type_t op) const;

    void UpdateWithOp(Parser::operator_type_t op, const Field* other);
    void UpdateWithOp(Parser::operator_type_t op);
};
using IntFieldPtr = std::unique_ptr<IntField, FieldDeleteFunc>;

}
