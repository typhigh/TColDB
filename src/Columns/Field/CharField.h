#pragma once
#include "Field.h"
namespace Columns {

/// Means Fix length string not single char
class CharField : public Field
{
private:
    /* data */
    std::string data;
public:
    CharField(/* args */) {}
    CharField(const std::string& data) : data(data) {}
    ~CharField() {}
    Parser::FieldType_t GetType() const;
    std::string ToString() const;
    FieldPtr Clone() const;
    std::string GetData() const;
    void SetData(const std::string& data);

public:
    bool Compare(Parser::operator_type_t op, const Field* other) const;
    bool Query(Parser::operator_type_t op) const;

    FieldPtr Op(Parser::operator_type_t op, const Field* other) const;
    FieldPtr Op(Parser::operator_type_t op) const;

    void UpdateWithOp(Parser::operator_type_t op, const Field* other);
    void UpdateWithOp(Parser::operator_type_t op);
};

using CharFieldPtr = std::unique_ptr<CharField, FieldDeleteFunc>;
}