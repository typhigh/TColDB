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
    
    /// Writing table meta
    Columns::TableMetaWritePtr writeTableMeta;

    /// Executor 
    ExecutorPtr executor;

public:
    ExecutorContext(const std::vector<Columns::TableMetaReadOnlyPtr>& tableMetas, ExecutorPtr executor);
    ~ExecutorContext() {}

public:

    /// Gengerate plan context
    Plan::PlanContextPtr GetPlanContext();
    
    /// Fetch field by (tableName opt) row's id and col's id
    Columns::FieldPtr FetchField(Columns::RowID rid, Columns::ColID cid) const;
    Columns::FieldPtr FetchField(const std::string& tableName, Columns::RowID rid, Columns::ColID cid) const;
    
    /// Get tupleDesc by (tableName opt)
    Columns::TupleDescPtr GetTableTupleDesc() const;
    Columns::TupleDescPtr GetTableTupleDesc(const std::string& tableName) const;


private:
    Columns::TableMetaReadOnlyPtr GetTableMeta(const std::string& tableName) const;
};

using ExecutorContextPtr = std::shared_ptr<ExecutorContext>;
}