#pragma once
#include "defs.h"
#include "../Utils/AdaptiveMap.h"
#include "../Columns/Field/Field.h"
#include "ColumnBlockID.h"
namespace Storages {

class ColumnBlockMeta
{
/// File and position information
private:
    std::string columnFile;
    size_t pos;
    size_t len;

/// Data statistical information
private:
    Columns::FieldPtr minValue;
    Columns::FieldPtr maxValue;
    Columns::FieldPtr sumValue;
    size_t count;

/// 
private:
;
public:
    ColumnBlockMeta(/* args */) {}
    ~ColumnBlockMeta() {}
};

using ColumnBlockMetaPtr = std::shared_ptr<ColumnBlockMeta>;
using ColumnBlockMetas = Utils::AdaptiveMap<ColumnBlockID, ColumnBlockMetaPtr>;
}