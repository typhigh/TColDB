#pragma once
#include "defs.h"
#include "ColumnBlockID.h"
#include "ColumnBlock.h"
#include "BufferPool.h"
#include "ColumnBlockMeta.h"
#include "OnDiskColumn.h"
namespace Storages {

class OnDiskTable
{
private:
    /* data */
    OnDiskColumns onDiskColumns;
    const static Columns::ColID startCid;

public:
    OnDiskTable() {}
    ~OnDiskTable() {}

    /// Get block from bufferPool or disk
    /// If bufferPool == nullptr, just fetch on disk
    bool GetColumnBlock(Columns::ColID cid, ColumnBlockID blockID, ColumnBlockPtr& block, BufferPoolPtr bufferPool);
    
    /// Insert block
    /// If bufferPool is not nullptr, add the block to bufferPool either
    bool InsertColumnBlock(Columns::ColID cid, ColumnBlockID blockID, ColumnBlockPtr block, BufferPoolPtr bufferPool);

    /// Get blockID by (rid,cid)
    bool GetBlockID(Columns::RowID rid, Columns::ColID cid, ColumnBlockID& blockID) const;

private:
    /// Get block from disk
    bool GetColumnBlockOnDisk(Columns::ColID cid, ColumnBlockID blockID, ColumnBlockPtr& block);
    
    /// Insert block to disk
    bool InsertColumnBlockOnDisk(Columns::ColID cid, ColumnBlockID blockID, ColumnBlockPtr block);
};

}