#include "ExecutorContext.h"
#include "../Plan/PlanContext.h"
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

Columns::FieldPtr ExecutorContext::FetchField(Columns::RowID rid, Columns::ColID cid) const
{
    if (tableMetas.size() != 1) {
        LOG_ERROR("expected only one tableMeta");
        return nullptr;
    }

    Columns::TableMetaReadOnlyPtr tableMeta = tableMetas[0]; 
    return tableMeta->GetField(rid, cid);
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

Columns::TupleDescPtr ExecutorContext::GetTableTupleDesc() const
{
    if (tableMetas.size() != 1) {
        LOG_ERROR("expected only one tableMeta");
        return nullptr;
    }
    Columns::TableMetaReadOnlyPtr tableMeta = tableMetas[0];
    return tableMeta->GetTupleDescCopy();
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