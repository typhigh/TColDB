#pragma once
#include "defs.h"
#include "ColumnBlockID.h"
#include "../Columns/ColID.h"
#include "../Columns/RowID.h"
#include "../Columns/Field/Field.h"

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

}