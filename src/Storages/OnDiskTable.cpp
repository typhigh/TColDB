#include "OnDiskTable.h"
using namespace std;

namespace Storages {

const Columns::ColID OnDiskTable::startCid = Columns::ColID(0);

OnDiskTablePtr OnDiskTable::Clone() const 
{
    OnDiskTablePtr ret = make_shared<OnDiskTable>();
    for (OnDiskColumnPtr column : this->onDiskColumns) {
        ret->onDiskColumns.push_back(column);
    }
    return ret;
}

bool OnDiskTable::GetColumnBlock(Columns::ColID cid, ColumnBlockID blockID, ColumnBlockPtr& block, BufferPoolPtr bufferPool)
{
    /// First find the bufferPool
    if (bufferPool != nullptr && ((block = bufferPool->Get(blockID)) != nullptr)) {
        return true;
    }

    /// Cache Miss, just fetch disk 
    if (!GetColumnBlockOnDisk(cid, blockID, block)) {
        return false;
    } 

    /// Insert it to bufferPool
    if (bufferPool != nullptr) {
        bufferPool->Insert(blockID, block);
    }
    return true;
}

bool OnDiskTable::InsertColumnBlock(Columns::ColID cid, ColumnBlockID blockID, ColumnBlockPtr block, BufferPoolPtr bufferPool)
{   
    bool ret = InsertColumnBlockOnDisk(cid, blockID, block);
    if (ret && bufferPool != nullptr) {
        bufferPool->Insert(blockID, block);
    }
    return ret;
}

bool OnDiskTable::GetBlockID(Columns::RowID rid, Columns::ColID cid, ColumnBlockID& blockID) const
{
    size_t pos = startCid.Offset(cid);
    assert(pos < onDiskColumns.size());
    return onDiskColumns[pos]->GetBlockID(rid, blockID);
}
    

bool OnDiskTable::GetColumnBlockOnDisk(Columns::ColID cid, ColumnBlockID blockID, ColumnBlockPtr& block)
{
    size_t pos = startCid.Offset(cid);
    assert(pos < onDiskColumns.size());
    return onDiskColumns[pos]->GetColumnBlockOnDisk(blockID, block);
}

bool OnDiskTable::InsertColumnBlockOnDisk(Columns::ColID cid, ColumnBlockID blockID, ColumnBlockPtr block)
{
    size_t pos = startCid.Offset(cid);
    assert(pos < onDiskColumns.size());
    return onDiskColumns[pos]->InsertColumnBlockOnDisk(blockID, block);
}

}