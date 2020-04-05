#pragma once
#include "ColID.h"
#include "TableID.h"
#include "../Parser/defs.h"
#include "../Plan/RenameTable.h"
#include <string>
#include <memory>

namespace Columns {
class ColumnDesc
{
private:
    /// Basic information
    std::string fieldName;
    Parser::FieldType_t fieldType;
    int width;
    bool unique;
    bool primary;

    /// Helpful information
    ColID cid;
    TableID tableID;

public: 
    ColumnDesc(/* args */) {}
    ColumnDesc(const std::string& fieldName, Parser::FieldType_t fieldType)
        : fieldName(fieldName), fieldType(fieldType) {}
    ~ColumnDesc() {}

    std::string ToString() const;
    void SetAlis(std::string alis, bool isTableAlis = true);
    void SetAlis(const Plan::RenameTable& rename);
    std::string GetFieldName() const;
    
    /// Used for sort
    bool operator < (const ColumnDesc& other) const {
        if (tableID != other.tableID) {
            return tableID < other.tableID;
        }
        return cid < other.cid;
    }
};

using ColumnDescPtr = std::shared_ptr<ColumnDesc>; 
using ColumnDescs = std::vector<ColumnDesc>;
}