#include "Table.h"
using namespace std;

namespace Columns {

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

}
