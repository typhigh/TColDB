#pragma once
#include "defs.h"
#include "../Utils/AdaptiveMap.h"
#include "ColumnBlockStatistics.h"
#include "ColumnBlockID.h"
#include "ColumnBlock.h"
namespace Storages {

class ColumnBlockMeta
{
/// File and position information
private:
    std::string columnFile;
    size_t pos;
    size_t len;

/// Data statistical information
    ColumnBlockStatistics statistics;
private:
;
public:
    ColumnBlockMeta() {}
    ~ColumnBlockMeta() {}
    ColumnBlockMetaPtr Clone() const;

public:
    ColumnBlockPtr GetBlock() const;
};

using ColumnBlockMetas = Utils::AdaptiveMap<ColumnBlockID, ColumnBlockMetaPtr>;
}