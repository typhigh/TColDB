#pragma once
#include "Field.h"

namespace Columns {

class DateField : public Field
{
private:
    /* data */
    std::string data;
    
public:
    DateField(/* args */) {}
    DateField(const std::string data) : data(data) {}
    ~DateField() {}
    Parser::FieldType_t GetType() const;
    std::string ToString() const;
    FieldPtr Clone() const;
    std::string GetData() const;
    void SetData(const std::string& data);
/// Operations def
public:
    bool Compare(Parser::operator_type_t op, const Field* other) const;
    bool Query(Parser::operator_type_t op) const;

    FieldPtr Op(Parser::operator_type_t op, const Field* other) const;
    FieldPtr Op(Parser::operator_type_t op) const;

    void UpdateWithOp(Parser::operator_type_t op, const Field* other);
    void UpdateWithOp(Parser::operator_type_t op);
};

using DateFieldPtr = std::unique_ptr<DateField, FieldDeleteFunc>;

}