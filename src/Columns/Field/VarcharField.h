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
    VarcharField(const std::string& data) {}
    ~VarcharField() {}
    Parser::FieldType_t GetType() const;
    std::string ToString() const;
    FieldPtr Clone() const = 0;
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

using VarcharFieldPtr = std::unique_ptr<VarcharField, FieldDeleteFunc>;

}