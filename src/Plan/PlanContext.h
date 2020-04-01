#pragma once
#include "../Executor/ExecutorContext.h"
#include "defs.h"
#include "../Columns/TableMeta.h"
namespace Plan {

class PlanContext
{
private:
    Executor::ExecutorContextPtr context;

public:
    PlanContext(const Executor::ExecutorContextPtr context) : context(context) {}
    ~PlanContext() {}

/// Just used for Plan
public:
    /// Fetch field by (tableName opt) row's id and col's id
    Columns::FieldPtr FetchField(Columns::RowID rid, Columns::ColID cid) const;
    Columns::FieldPtr FetchField(const std::string& tableName, Columns::RowID rid, Columns::ColID cid) const;
    
    /// Get tupleDesc by (tableName opt)
    Columns::TupleDescPtr GetTableTupleDesc() const;
    Columns::TupleDescPtr GetTableTupleDesc(const std::string& tableName) const;

};

using PlanContextPtr = std::shared_ptr<PlanContext>;

}