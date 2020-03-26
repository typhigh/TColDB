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
    ~CharField() {}
    bool IsType(Parser::FieldType type) const;
    std::string ToString() const;
    std::string GetData() const;
    void SetData(const std::string& data);
/// Operations def
public:
    FieldPtr Op(Parser::operator_type_t op, const FieldPtr other) const;
    FieldPtr Op(Parser::operator_type_t op) const;
};

using CharFieldPtr = Utils::ObjectPool<CharField>::ObjectPtr;
}