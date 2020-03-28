#pragma once
#include "../Parser/defs.h"
#include <string>
#include <memory>

namespace Columns {
class ColumnDesc
{
private:
    std::string fieldName;
    Parser::FieldType_t fieldType;

public: 
    ColumnDesc(/* args */) {}
    ~ColumnDesc() {}

    void SetAlis(std::string alis, bool isTableAlis = true);
    
};

using ColumnDescPtr = std::shared_ptr<ColumnDesc>; 
}