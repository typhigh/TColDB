#include "ExecutorContext.h"
#include "../Plan/PlanContext.h"
#include "Executor.h"
using namespace std;

namespace Executor {

ExecutorContext::ExecutorContext(
    const std::vector<Columns::TableMetaReadOnlyPtr>& tableMetas,
    const std::vector<Columns::TableID> tableIDs,
    ExecutorPtr executor)
    : tableMetas(tableMetas)
    , tableIDs(tableIDs)
    , executor(executor)
{
}

Plan::PlanContextPtr ExecutorContext::GetPlanContext()
{
    return make_shared<Plan::PlanContext>(shared_from_this());
}

Columns::FieldPtr ExecutorContext::FetchField(Columns::TableID tableID, Columns::RowID rid, Columns::ColID cid) const
{
    Columns::TableMetaReadOnlyPtr tableMeta = GetTableMeta(tableID);
    if (tableMeta == nullptr) {
        LOG_WARN("No such table");
        return nullptr;
    }
    return tableMeta->GetField(rid, cid);    
}

Columns::TableID ExecutorContext::GetTableID(const string& tableName) const 
{
    for (size_t i = 0; i < tableMetas.size(); ++i) {
        if (tableMetas[i]->GetTableName() == tableName) {
            return tableIDs[i];
        }
    }   
    LOG_WARN("No such table %s", tableName.c_str());
    return Columns::NullTableID;
}

Columns::TupleDescPtr ExecutorContext::GetTableTupleDesc(Columns::TableID tableID) const
{
    Columns::TableMetaReadOnlyPtr tableMeta = GetTableMeta(tableID);
    if (tableMeta == nullptr) {
        LOG_WARN("No such table");
        return nullptr;
    }
    return tableMeta->GetTupleDescCopy();
}

size_t ExecutorContext::GetTupleCount(Columns::TableID tableID) const 
{
    Columns::TableMetaReadOnlyPtr tableMeta = GetTableMeta(tableID);
    if (tableMeta == nullptr) {
        LOG_WARN("No such table");
        return 0;
    }
    return tableMeta->GetTupleCount();
}

void ExecutorContext::SubmitTableMeta(Columns::TableID tableID, Columns::TableMetaWritePtr tableMeta)
{
    this->executor->SumbitTableMeta(tableID, tableMeta);   
}

Columns::TableMetaReadOnlyPtr ExecutorContext::GetTableMeta(Columns::TableID tableID) const 
{
    for (size_t i = 0; i < tableIDs.size(); ++i) {
        if (tableIDs[i] == tableID) {
            return tableMetas[i];
        }
    }
    return nullptr;
}
}