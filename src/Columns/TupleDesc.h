#pragma once
#include "ColumnDesc.h"
#include <memory>
#include <vector>
namespace Columns {
class TupleDesc
{
private:
    /* data */
    std::vector<ColumnDesc> desc;

public:
    TupleDesc(/* args */);
    ~TupleDesc();
};

using TupleDescPtr = std::shared_ptr<TupleDesc>;

}