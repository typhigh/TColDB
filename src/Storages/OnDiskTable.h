#pragma once
#include "defs.h"
#include "ColumnBlockID.h"
#include "ColumnBlock.h"
#include "BufferPool.h"
#include "ColumnBlockMeta.h"

namespace Storages {

class OnDiskTable
{
private:
    /* data */
    ColumnBlockMetas blockMetas;
    
public:
    OnDiskTable() {}
    ~OnDiskTable() {}

    /// Get block from bufferPool or disk
    /// If bufferPool == nullptr, just fetch on disk
    void GetColumnBlock(ColumnBlockID blockID, ColumnBlockPtr& block, BufferPoolPtr bufferPool);
    
    /// Insert block
    /// If bufferPool is not nullptr, add the block to bufferPool either
    void InsertColumnBlock(ColumnBlockID blockID, ColumnBlockPtr block, BufferPoolPtr bufferPool);

private:
    /// Get block from disk
    void GetColumnBlockOnDisk(ColumnBlockID blockID, ColumnBlockPtr& block);
};

}