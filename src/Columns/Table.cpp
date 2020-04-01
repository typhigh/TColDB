#include "Table.h"
using namespace std;

namespace Columns {

TableMetaReadOnlyPtr Table::GetCurrentTableMeta(bool isReadOnly) const
{
    if (isReadOnly) {
        return GetCurrentReadOnlyTableMeta();
    } else {
        return GetCurrentWriteTableMeta();
    }
}

TableMetaReadOnlyPtr Table::GetCurrentReadOnlyTableMeta() const
{
    return currentReadOnlyTableMeta.get();
}

TableMetaReadOnlyPtr Table::GetCurrentWriteTableMeta() const
{
    return currentWriteTableMeta.get();
}

void Table::SetCurrentReadOnlyTableMeta(TableMetaReadOnlyPtr && tableMeta) 
{
    currentReadOnlyTableMeta.set(move(tableMeta));
}

void Table::SetCurrentWriteTableMeta(TableMetaReadOnlyPtr && tableMeta)
{
    currentWriteTableMeta.set(move(tableMeta));
}

bool Table::TryWriteLock() 
{
    bool expected = false;
    if (isWriting.compare_exchange_strong(expected, true)) {
        return true;
    }
    return false;
}

void Table::ReleaseWriteLock()
{
    bool expected = true;
    isWriting.compare_exchange_strong(expected, false);
}

}
