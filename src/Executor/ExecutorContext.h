#pragma once
#include "defs.h"
#include "../Common/CommandWrap.h"
#include "../Columns/TableMeta.h"
#include "../Plan/defs.h"
namespace Executor {

class ExecutorContext : std::enable_shared_from_this<ExecutorContext>
{
private:
    /// ReadOnly table meta (snapshot) 
    const std::vector<Columns::TableMetaReadOnlyPtr> tableMetas;

    const std::vector<Columns::TableID> tableIDs;

    const std::vector<std::string> tableNames;

    /// Writing table meta
    Columns::TableMetaWritePtr writeTableMeta;

    /// Executor 
    ExecutorPtr executor;

    /// The client id
    Common::CommandWrapPtr command;

public:
    ExecutorContext(const std::vector<Columns::TableMetaReadOnlyPtr>& tableMetas, 
                    const std::vector<Columns::TableID>& tableIDs, 
                    const std::vector<std::string>& tableNames, 
                    Common::CommandWrapPtr command,
                    ExecutorPtr executor);
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

    /// Get the table meta
    Columns::TableMetaReadOnlyPtr GetTableMeta(Columns::TableID tableID) const;

public:
    /// Submit the new table meta
    void SubmitTableMeta(Columns::TableID tableID, Columns::TableMetaWritePtr tableMeta);

    /// Submit the commit
    void SubmitCommit();

    /// Submit the exit 
    void SubmitExit();

    /// Submit the result to the client
    void SubmitResult(const std::string& result);
};

using ExecutorContextPtr = std::shared_ptr<ExecutorContext>;
}