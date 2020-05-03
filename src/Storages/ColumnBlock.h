#pragma once
#include "defs.h"
#include "ColumnBlockID.h"
#include "../Columns/ColID.h"
#include "../Columns/RowID.h"
#include "../Columns/Field/Field.h"
#include "../Utils/AdaptiveMap.h"

namespace Storages {

class ColumnBlock
{
private:
    /* data */
    Columns::ColID cid;
    Columns::RowID startID;
    std::vector<Columns::FieldPtr> fields;
    
public:
    ColumnBlock(/* args */) {}
    ~ColumnBlock() {}

    
};
using ColumnBlockPtr = std::shared_ptr<ColumnBlock>;
using ColumnBlocks = Utils::AdaptiveMap<ColumnBlockID, ColumnBlockPtr>;

}