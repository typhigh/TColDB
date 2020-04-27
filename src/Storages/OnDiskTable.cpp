#include "OnDiskTable.h"
using namespace std;

namespace Storages {

void OnDiskTable::GetColumnBlock(ColumnBlockID blockID, ColumnBlockPtr& block, BufferPoolPtr bufferPool)
{
    /// First find the bufferPool
    if (bufferPool != nullptr && ((block = bufferPool->Get(blockID)) != nullptr)) {
        return;
    }

    /// Cache Miss, just fetch disk 
    GetColumnBlockOnDisk(blockID, block);
    if (block == nullptr) {
        return;
    } 

    /// Insert it to bufferPool
    if (bufferPool != nullptr) {
        bufferPool->Insert(blockID, block);
    }
}

void OnDiskTable::InsertColumnBlock(ColumnBlockID blockID, ColumnBlockPtr block, BufferPoolPtr bufferPool)
{
    
}

void OnDiskTable::GetColumnBlockOnDisk(ColumnBlockID blockID, ColumnBlockPtr& block)
{
        
}

}