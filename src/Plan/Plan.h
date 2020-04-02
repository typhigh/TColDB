#pragma once
#include "defs.h"
#include "PlanContext.h"
#include "PlanVisitor.h"
#include "../Columns/TupleDesc.h"
#include <memory>

namespace Plan {

using Plans = std::vector<PlanPtr>;
using FieldNames = std::vector<std::string>;
class Plan
{
private:
    PlanPtr parent;

    /// the field names used from the 
    /// Set at the "TupleDescSetPrevious"
    FieldNames fieldNames;
    
    /// the tupledesc at the node
    /// Set at the "TupleDescSetEnd"
    Columns::TupleDescPtr desc;

protected:
    PlanContextPtr context;

public:
    Plan(PlanContextPtr context) : context(context){};
    virtual ~Plan() {}

public:
    void SetPlanContext(PlanContextPtr context);
    PlanPtr GetParent();
    void SetParent(PlanPtr parent);
    void SetFieldNames(FieldNames fieldNames);
    void SetTupleDesc(Columns::TupleDescPtr desc);

public:
    /// Accept the visitor (visit design pattern)
    virtual bool Accept (PlanVisitorPtr visitor, PlanPtr& result) = 0;
    
    /// Get the plan type
    virtual PlanType_t GetType() const = 0;
    
    /// Get all children
    virtual Plans GetChildren() = 0;

    /// Get the ref columns ref just in this node (not as the 'fieldNames')
    virtual FieldNames GetColumnsRef() const = 0;
    
//    virtual void Execute(Executor::ExecutorContext context) const = 0;
};


}