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
    ~TupleDesc() {}
    TupleDescPtr Clone() const;

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

    TupleDescPtr GetFieldsNoByFrom(TupleDescPtr from) const;
};

using TupleDescPtr = std::shared_ptr<TupleDesc>;
using TupleDescs = std::vector<TupleDescPtr>;
}