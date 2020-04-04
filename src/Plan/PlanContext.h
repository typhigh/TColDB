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

    /// Get tupleDesc by (tableID opt)
    Columns::TupleDescPtr GetTableTupleDesc() const;
    Columns::TupleDescPtr GetTableTupleDesc(Columns::TableID tableID) const;
};

using PlanContextPtr = std::shared_ptr<PlanContext>;

}