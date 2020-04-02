#pragma once
#include "ColID.h"
#include "TableID.h"
#include "../Parser/defs.h"
#include <string>
#include <memory>

namespace Columns {
class ColumnDesc
{
private:
    /// Basic information
    std::string fieldName;
    Parser::FieldType_t fieldType;

    /// Helpful information
    ColID cid;
    TableID tableID;

public: 
    ColumnDesc(/* args */) {}
    ~ColumnDesc() {}

    void SetAlis(std::string alis, bool isTableAlis = true);
    std::string GetFieldName() const;
};

using ColumnDescPtr = std::shared_ptr<ColumnDesc>; 
}