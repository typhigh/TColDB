#pragma once
#include "../Parser/FieldType.h"
#include <string>
#include <memory>

namespace Columns {
class ColumnDesc
{
private:
    std::string fieldName;
    Parser::FieldType fieldType;

public: 
    ColumnDesc(/* args */);
    ~ColumnDesc();
};

using ColumnDescPtr = std::shared_ptr<ColumnDesc>; 
}