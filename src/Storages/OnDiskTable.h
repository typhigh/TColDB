#pragma once
#include "defs.h"
#include "ColumnBlockID.h"
#include "ColumnBlock.h"
#include "BufferPool.h"

namespace Storages {

class OnDiskTable
{
private:
    /* data */
    /// TODO:Maybe bufferPool can be owned by tableMeta(OnDiskTable)
    /// BufferPool pool;

    /// BufferPool's refer
    BufferPoolPtr pool;

public:
    OnDiskTable(BufferPoolPtr pool) : pool(pool) {}
    ~OnDiskTable() {}

    void GetColumnBlock(ColumnBlockID blockID);
    void InsertColumnBlock(ColumnBlockID blockID, ColumnBlockPtr block);
};

}