#pragma once
#include "defs.h"
#include "ColumnBlockID.h"
#include "ColumnBlock.h"
#include "../Utils/LRUCache.h"

namespace Storages {

class BufferPool
{
private:
    Utils::LRUCache<ColumnBlockID, ColumnBlock, Common::IDHashFunc> pool;

public:
    BufferPool(/* args */) {}
    ~BufferPool() {}

    /// Insert the block
    void Insert(ColumnBlockID id, ColumnBlockPtr block);

    /// Get the block
    ColumnBlockPtr Get(ColumnBlockID id);
};

using BufferPoolPtr = std::shared_ptr<BufferPool>;
}