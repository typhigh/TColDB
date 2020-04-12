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
    int width = 0;
    bool unique = false;
    bool primary = false;

    /// Helpful information
    ColID cid;
    TableID tableID;

public: 
    ColumnDesc(const std::string& fieldName, Parser::FieldType_t fieldType, TableID tableID, ColID cid);
    ~ColumnDesc() {}

    std::string ToString(const std::string& prefix) const;
    void SetAlis(std::string alis, bool isTableAlis = true);
    void SetAlis(const Plan::RenameTable& rename);
    void SetPrimary();
    void SetUnique();
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