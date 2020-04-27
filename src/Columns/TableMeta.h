#pragma once
#include "defs.h"
#include "TupleDesc.h"
#include "RowID.h"
#include "ColID.h"
#include "TableID.h"
#include "Field/Field.h"
#include "../Executor/Operators/Predicator.h"
#include "../ThreePart/CRoaring/roaring.hh"
#include "../Storages/OnDiskTable.h"
#include "../Storages/InMemoryTable.h"
#include "../Storages/BufferPool.h"
#include <memory>

namespace Columns {

class TableMeta
{
private:
    /// data with state
    std::string tableName; 
    TableID tableID;

    ColID currentCID;
    RowID currentRID;

    Storages::OnDiskTable onDiskTable;
    Storages::InMemoryTable inMemoryTable;
//    IndexPartMetaPtr IndexPartMeta;
    
    TupleDescPtr tupleDesc;
    
    /// Check(constraint) condition
    Executor::PredicatorPtr checker;

    /// Default field value
    std::vector<FieldPtr> defaultFields;    

    /// Bitset of rows
    Roaring rowBitest;

public:
    TableMeta(const std::string& tableName, TableID tableID);
    ~TableMeta() {}
    
    /// Get the informations
    std::string ToString() const;

    /// Get the table tuple desc copy
    TupleDescPtr GetTupleDescCopy() const;

    /// Set the table tuple desc
    void SetTupleDesc(TupleDescPtr desc);

    /// Get the table name
    std::string GetTableName() const;
    
    /// Get field
    FieldPtr GetField(RowID rid, ColID cid, Storages::BufferPoolPtr bufferPool) const;
    
    /// Get tuple count
    size_t GetTupleCount() const;

    /// Set checker
    void SetChecker(Executor::PredicatorPtr checker);

    /// Check if the tuple is under the constraint 
    bool CheckCondition(TuplePtr tuple) const;

    /// Create next col id
    ColID CreateNextColID();


public:
    TableMetaReadOnlyPtr CloneReadOnly() const;

    /// Clone
    TableMetaWritePtr CloneWrite() const;

/// Bitset 
public:
    /// Check field (rid, cid) is available (in range)
    bool CheckInRange(RowID rid, ColID cid) const;

    /// Check rid is available
    bool CheckInRange(RowID rid) const;

    /// Delete the row, return true if no error
    bool DeleteRow(RowID rid);

    /// Insert the row, return true if no error
    bool InsertRow(TuplePtr tuple, std::string& error);

private:
    void InsertRowImpl(TuplePtr tuple);
};

}