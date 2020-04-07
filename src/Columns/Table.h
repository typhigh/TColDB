#pragma once
#include "TableMeta.h"
#include "../Utils/MultiVersion.h"
#include <atomic>
namespace Columns {

class Table
{
private:
    /* data */
    MultiVersion<TableMeta> currentReadOnlyTableMeta;
    MultiVersion<TableMeta> currentWriteTableMeta;
    std::atomic<bool> isWriting;

public:
    Table() {isWriting.store(false);}
    ~Table() {}
    
    /// Get the table meta, given if read only
    TableMetaReadOnlyPtr GetCurrentTableMeta(bool isReadOnly) const;
    void SetCurrentReadOnlyTableMeta(TableMetaReadOnlyPtr tableMeta);
    void SetCurrentWriteTableMeta(TableMetaReadOnlyPtr tableMeta); 
    void Update();
    /// Try lock the table before write, if it's hold by others, return false
    bool TryWriteLock();

    /// Try release the lock after write
    void ReleaseWriteLock();

private:
    
    /// Get the current read only meta
    TableMetaReadOnlyPtr GetCurrentReadOnlyTableMeta() const;

    /// Get the current write meta
    /// The current write table meta is only read, we should create a newer version 
    TableMetaReadOnlyPtr GetCurrentWriteTableMeta() const;

};

using TablePtr = std::shared_ptr<Table>;
}