#include "ColumnBlockMeta.h"
#include "Slice.h"
using namespace std;

namespace Storages {

ColumnBlockMetaPtr ColumnBlockMeta::Clone() const 
{
    ColumnBlockMetaPtr ret = make_shared<ColumnBlockMeta>();
    
    ret->columnFile = this->columnFile;
    ret->pos = this->pos;
    ret->len = this->len;
    ret->statistics = statistics.Clone();

    /// TODO:
    return ret;
}

ColumnBlockPtr ColumnBlockMeta::GetBlock() const
{
    /// TODO: use iterator to get block
    ColumnBlockPtr block;
    
}

}