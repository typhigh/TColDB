#pragma once
#include "ColumnBlockMeta.h"
#include "ColumnBlock.h"
namespace Storages {

class OnDiskColumn
{
private:
    /* data */
    using BlockIDs = Utils::AdaptiveMap<Columns::RowID, ColumnBlockID>; 
    ColumnBlockMetas blockMetas;
    BlockIDs blockIDs;

public:
    OnDiskColumn(/* args */) {}
    ~OnDiskColumn() {}

    /// Clone func
    OnDiskColumnPtr Clone() const;

    /// Get block from disk
    bool GetColumnBlockOnDisk(ColumnBlockID blockID, ColumnBlockPtr& block);
    
    /// Insert block to disk
    bool InsertColumnBlockOnDisk(ColumnBlockID blockID, ColumnBlockPtr block);

    /// Get blockID by rid
    bool GetBlockID(Columns::RowID rid, ColumnBlockID& blockID) const;

private:
    
};

}