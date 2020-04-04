#pragma once
#include "defs.h"
#include "TupleDesc.h"
#include "RowID.h"
#include "ColID.h"
#include "TableID.h"
#include "Field/Field.h"
#include <memory>

namespace Columns {

class TableMeta
{
private:
    /// data with state
    std::string tabelName; 
    TableID tableID;
//    TablePartMetaPtr tablePartMeta;
//    IndexPartMetaPtr IndexPartMeta;
    TupleDescPtr tupleDesc;
public:
    TableMeta(/* args */) {}
    ~TableMeta() {}
    TupleDescPtr GetTupleDesc() const;
    std::string GetTableName() const;
    FieldPtr GetField(RowID rid, ColID cid) const;

public:
    TableMetaReadOnlyPtr CloneReadOnly() const;
    TableMetaWritePtr CloneWrite() const;
};

}