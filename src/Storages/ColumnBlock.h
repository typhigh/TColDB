#pragma once
#include "defs.h"
#include "ColumnBlockID.h"
#include "ColumnBlockStatistics.h"
#include "../Columns/ColID.h"
#include "../Columns/RowID.h"
#include "../Utils/AdaptiveMap.h"

namespace Storages {

class ColumnBlock
{
private:
    /* data */
    Columns::ColID cid;
    Columns::RowID startID;
    std::vector<Columns::FieldPtr> fields;
    ColumnBlockStatistics statistics;
    
public:
    ColumnBlock(/* args */) {}
    ~ColumnBlock() {}

    /// Get some field copy
    Columns::FieldPtr GetFieldCopy(Columns::RowID rid) const;    

    /// Get statistics
    ColumnBlockStatistics GetStatistics() const;
};
using ColumnBlockPtr = std::shared_ptr<ColumnBlock>;
using ColumnBlocks = Utils::AdaptiveMap<ColumnBlockID, ColumnBlockPtr>;

}