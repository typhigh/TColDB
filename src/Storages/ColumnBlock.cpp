#include "ColumnBlock.h"
using namespace std;

namespace Storages {

Columns::FieldPtr ColumnBlock::GetFieldCopy(Columns::RowID rid) const 
{
    return fields[startID.Offset(rid)]->Clone();
}

ColumnBlockStatistics ColumnBlock::GetStatistics() const 
{
    return statistics.Clone();
}

}