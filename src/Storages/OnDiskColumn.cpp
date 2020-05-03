#include "OnDiskColumn.h"
using namespace std;

namespace Storages {


bool OnDiskColumn::GetColumnBlockOnDisk(ColumnBlockID blockID, ColumnBlockPtr& block)
{
    ColumnBlockMetaPtr blockMeta;
    if (!blockMetas.Get(blockID, blockMeta)) {
        LOG_WARN("No such block whose id is %s", blockID.ToString().c_str());
        return false;
    }

    
}

bool OnDiskColumn::InsertColumnBlockOnDisk(ColumnBlockID blockID, ColumnBlockPtr block)
{

}

bool OnDiskColumn::GetBlockID(Columns::RowID rid, ColumnBlockID& blockID) const
{
    return blockIDs.LowBound(rid, blockID);
}

}