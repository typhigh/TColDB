#include "ExecutorContext.h"
#include "../Plan/PlanContext.h"
#include "Executor.h"
using namespace std;

namespace Executor {

ExecutorContext::ExecutorContext(
    const vector<Columns::TableMetaReadOnlyPtr>& tableMetas,
    const vector<Columns::TableID>& tableIDs,
    const vector<string>& tableNames,
    Common::CommandWrapPtr command,
    ExecutorPtr executor,
    Storages::BufferPoolPtr bufferPool)
    : tableMetas(tableMetas)
    , tableIDs(tableIDs)
    , tableNames(tableNames)
    , command(command)
    , executor(executor)
    , bufferPool(bufferPool)
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
    return tableMeta->GetField(rid, cid, bufferPool);    
}

Columns::TableID ExecutorContext::GetTableID(const string& tableName) const 
{
    for (size_t i = 0; i < tableNames.size(); ++i) {
        if (tableNames[i] == tableName) {
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

Columns::TableMetaReadOnlyPtr ExecutorContext::GetTableMeta(Columns::TableID tableID) const 
{
    for (size_t i = 0; i < tableIDs.size(); ++i) {
        if (tableIDs[i] == tableID) {
            return tableMetas[i];
        }
    }
    return nullptr;
}

void ExecutorContext::SubmitTableMeta(Columns::TableID tableID, Columns::TableMetaWritePtr tableMeta)
{
    executor->SumbitTableMeta(tableID, tableMeta);   
}

void ExecutorContext::SubmitCommit() 
{
    executor->SubmitCommit(tableIDs[0]);
}

void ExecutorContext::SubmitExit()
{
    executor->RemoveClient(command->GetClientID());
}

void ExecutorContext::SubmitResult(const string& result)
{
    command->SetResult(result);
}

}