#include "OnDiskColumn.h"
using namespace std;

namespace Storages {

OnDiskColumnPtr OnDiskColumn::Clone() const
{
    OnDiskColumnPtr ret = make_shared<OnDiskColumn>();
    ret->blockIDs = this->blockIDs;
    
    /// Deep Copy blockMetas
    for (auto iter = blockMetas.Begin(); iter.HasNext(); ) {
        decltype(blockMetas)::KeyValue pair = iter.Next();
        ret->blockMetas.Insert(pair.first, pair.second->Clone());
    }
}

bool OnDiskColumn::GetColumnBlockOnDisk(ColumnBlockID blockID, ColumnBlockPtr& block)
{
    ColumnBlockMetaPtr blockMeta;
    if (!blockMetas.Get(blockID, blockMeta)) {
        LOG_WARN("No such block whose id is %s", blockID.ToString().c_str());
        return false;
    }
    /// TODO
    block = blockMeta->GetBlock();
    return true;
}

bool OnDiskColumn::InsertColumnBlockOnDisk(ColumnBlockID blockID, ColumnBlockPtr block)
{

}

bool OnDiskColumn::GetBlockID(Columns::RowID rid, ColumnBlockID& blockID) const
{
    return blockIDs.LowBound(rid, blockID);
}

}