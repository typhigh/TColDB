#pragma once
#include <memory>
#include "../../Parser/FieldType.h"

namespace Coulumns {
class Field
{
private:
    /* data */
public:
    Field(/* args */) {}
    virtual ~Field() {}
    virtual bool IsType(Parser::FieldType type) const = 0;
};

using FieldPtr = std::shared_ptr<Field>;
}