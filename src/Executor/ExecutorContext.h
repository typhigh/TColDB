#pragma once
#include "defs.h"
#include "../Columns/TableMeta.h"
#include "../Plan/defs.h"
namespace Executor {

class ExecutorContext : std::enable_shared_from_this<ExecutorContext>
{
private:
    /// ReadOnly table meta (snapshot) 
    const std::vector<Columns::TableMetaReadOnlyPtr> tableMetas;

    const std::vector<Columns::TableID> tableIDs;

    /// Writing table meta
    Columns::TableMetaWritePtr writeTableMeta;

    /// Executor 
    ExecutorPtr executor;

public:
    ExecutorContext(const std::vector<Columns::TableMetaReadOnlyPtr>& tableMetas, const std::vector<Columns::TableID> tableIDs, ExecutorPtr executor);
    ~ExecutorContext() {}

public:

    /// Gengerate plan context
    Plan::PlanContextPtr GetPlanContext();
    
    /// Fetch field by (tableName opt) row's id and col's id
    Columns::FieldPtr FetchField(Columns::TableID tableID, Columns::RowID rid, Columns::ColID cid) const;
    
    /// Get tableID by tableName
    Columns::TableID GetTableID(const std::string& tableName) const;

    /// Get tupleDesc by tableID
    Columns::TupleDescPtr GetTableTupleDesc(Columns::TableID tableID) const;

    /// Get table's tuple count
    size_t GetTupleCount(Columns::TableID tableID) const;

private:
    Columns::TableMetaReadOnlyPtr GetTableMeta(Columns::TableID tableID) const;
};

using ExecutorContextPtr = std::shared_ptr<ExecutorContext>;
}