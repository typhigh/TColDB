#include "Table.h"
using namespace std;

namespace Columns {

TableMetaPtr Table::GetCurrentReadOnlyTableMeta() const
{
    return currentReadOnlyTableMeta.get();
}

TableMetaPtr Table::GetCurrentWriteTableMeta() const
{
    return currentWriteTableMeta.get();
}

void Table::SetCurrentReadOnlyTableMeta(TableMetaPtr& tableMeta) 
{
    currentReadOnlyTableMeta.set(tableMeta);
}

void Table::SetCurrentWriteTableMeta(TableMetaPtr& tableMeta)
{
    currentWriteTableMeta.set(tableMeta);
}

}
