#pragma once
#include "ColumnDesc.h"
#include "../Plan/RenameTable.h"
#include "../Plan/defs.h"
#include <memory>
#include <vector>
namespace Columns {


class TupleDesc
{
private:
    /* data */
    ColumnDescs descs;
    
    /// If it's 
    std::string tableName;

    using TupleDescPtr = std::shared_ptr<TupleDesc>;

public:
    TupleDesc(/* args */) {}
    TupleDesc(const std::string& tableName, const ColumnDescs& descs) 
        : tableName(tableName), descs(descs) {}
    ~TupleDesc() {}
    TupleDescPtr Clone() const;

    /// Information
    std::string ToString(const std::string& prefix) const;

    /// Set alis
    void SetAlis(const Plan::RenameTable& rename);
    
    /// Get field name by fieldNo
    std::string GetFieldName(size_t fieldNo) const;

    /// Get columnDesc
    ColumnDescs GetColumnDescs() const;
    
    /// Merge other desc
    void MergeOnJoin(TupleDescPtr other);

    /// Get the fieldName's fieldNo, If none, return false
    bool GetFieldNo(const std::string& fieldName, int& fieldNo) const;
    
    std::string GetTableName() const;

    /// Set alis (another interface)
    void SetAlis(const std::string& alis);

    /// Mask by field names for columns eliminate
    void MaskByFieldNames(const Plan::FieldNames& fieldNames);

    std::vector<int> GetFieldsNoByFrom(TupleDescPtr from) const;
};

using TupleDescPtr = std::shared_ptr<TupleDesc>;
using TupleDescs = std::vector<TupleDescPtr>; 
}