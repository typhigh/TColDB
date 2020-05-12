#pragma once
#include "defs.h"
#include "ColumnBlock.h"

namespace Storages {
class ColumnBlockCreator
{
public:
    static ColumnBlockPtr CreateColumnBlock(
        Columns::ColID cid,
        Columns::RowID startID,
        ColumnBlockStatistics statistics
    );
};


}
