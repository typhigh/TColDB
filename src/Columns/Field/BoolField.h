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
    BoolField(bool data) : data(data){}
    ~BoolField() {}
    Parser::FieldType_t GetType() const;
    std::string ToString() const;
    FieldPtr Clone() const;
    bool GetData() const;
    void SetData(bool data);

/// Operations def
public:
    bool Compare(Parser::operator_type_t op, const Field* other) const;
    bool Query(Parser::operator_type_t op) const;

    FieldPtr Op(Parser::operator_type_t op, const Field* other) const;
    FieldPtr Op(Parser::operator_type_t op) const;

    void UpdateWithOp(Parser::operator_type_t op, const Field* other);
    void UpdateWithOp(Parser::operator_type_t op);
};

using BoolFieldPtr = std::unique_ptr<BoolField, FieldDeleteFunc>;
}
