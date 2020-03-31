#pragma once
#include "defs.h"
#include "../Columns/TableMeta.h"
#include "../Plan/PlanContext.h"
namespace Executor {

class ExecutorContext
{
private:
    /* data */
    const std::vector<Columns::TableMetaReadOnlyPtr> tableMetas;
    ExecutorPtr executor;

public:
    ExecutorContext(const std::vector<Columns::TableMetaReadOnlyPtr> tableMetas, ExecutorPtr executor);
    ~ExecutorContext() {}

public:
    Plan::PlanContextPtr GetPlanContext() const;   
    Columns::FieldPtr FetchField(const std::string& tableName, Columns::RowID rid, Columns::ColID cid);
    Columns::TupleDescPtr GetTableTupleDesc(const std::string& tableName) const;

};

using ExecutorContextPtr = std::shared_ptr<ExecutorContext>;
}