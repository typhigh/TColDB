#include "PlanContext.h"

#include "../Databases/Catalog.h"
#include "../Databases/Database.h"
using namespace std;

namespace Plan {

PlanContext::PlanContext(const vector<string>& tableNames, bool ReadOnly) 
{
    tableMetasRef.clear();
    tableMetasRef.resize(tableNames.size());
    for (size_t i = 0; i < tableNames.size(); ++i) {
        Columns::TablePtr table = Databases::Database::GetInstance()->GetCatalog()->GetTable(tableNames[i]);
        tableMetasRef[i] = ReadOnly ? table->GetCurrentReadOnlyTableMeta()
                                    : table->GetCurrentWriteTableMeta();
    }
}

Columns::TableMetaReadOnlyPtr PlanContext::GetTableMeta(const string& tableName) const
{
    for (int i = 0; i < tableMetasRef.size(); ++i) {
        if (tableMetasRef[i]->GetTableName() == tableName) {
            return tableMetasRef[i];
        }
    }
    return Columns::TableMetaReadOnlyPtr();
}

Columns::TableMetaReadOnlyPtr PlanContext::GetTableMeta() const 
{
    if (tableMetasRef.size() != 1) {
        LOG_ERROR("expected only one tableMeta");
        return Columns::TableMetaReadOnlyPtr();
    }
    return tableMetasRef[0];
}

}