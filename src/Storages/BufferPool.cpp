#include "BufferPool.h"
using namespace std;

namespace Storages {

void BufferPool::Insert(ColumnBlockID id, ColumnBlockPtr block)
{
    pool.Insert(id, block);
}

ColumnBlockPtr BufferPool::Get(ColumnBlockID id)
{
    return pool.Get(id);
}

}