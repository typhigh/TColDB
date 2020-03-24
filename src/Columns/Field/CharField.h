#pragma once
#include "Field.h"
namespace Columns {
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
};

using CharFieldPtr = std::shared_ptr<CharField>;
}