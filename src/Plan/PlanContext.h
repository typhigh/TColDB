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

    /// Get tableID by tableName
    Columns::TableID GetTableID(const std::string& tableName) const;

    /// Get tupleDesc by tableID
    Columns::TupleDescPtr GetTableTupleDesc(Columns::TableID tableID) const;

    /// Get tupleCount by tableID
    size_t GetTupleCount(Columns::TableID tableID) const;
};

using PlanContextPtr = std::shared_ptr<PlanContext>;

}