#pragma once
#include "defs.h"

namespace Storages {

class ColumnBlockMeta
{
private:
    

public:
    ColumnBlockMeta(/* args */) {}
    ~ColumnBlockMeta() {}
};

using ColumnBlockMetaPtr = std::shared_ptr<ColumnBlockMeta>;
using ColumnBlockMetas = std::vector<ColumnBlockMeta>;
}