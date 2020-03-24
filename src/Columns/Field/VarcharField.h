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
    ~VarcharField() {}
    bool IsType(Parser::FieldType type) const;
    std::string ToString() const;
};

using VarcharFieldPtr = std::shared_ptr<VarcharField>;
}