#pragma once
#include "defs.h"
#include "PlanContext.h"
#include "PlanVisitor.h"
#include "RenameTable.h"
#include "../Columns/TupleDesc.h"
#include <memory>

namespace Plan {

using Plans = std::vector<PlanPtr>;

class Plan
{
private:
    PlanPtr parent;

    /// the field names used from the 
    /// Set at the "TupleDescSetPrevious"
    FieldNames fieldNames;

    /// Rename Table
    RenameTable renameTable;

    /// if it's select * xxx
    bool selectAll;

protected:
    PlanContextPtr context;
    
    std::vector<int> fieldsNo;

    /// the tupledesc at the node
    /// Set at the "TupleDescSetEnd"
    Columns::TupleDescPtr desc;

public:
    Plan(PlanContextPtr context) : context(context), selectAll(false) {};
    virtual ~Plan() {}

public:
    /// Get the plan context
    PlanContextPtr GetPlanContext() const;

    /// Set the plan context
    void SetPlanContext(PlanContextPtr context);
    
    /// Get parent plan node
    PlanPtr GetParent();

    /// Set parent plan node
    void SetParent(PlanPtr parent);

    /// Get fieldNames
    FieldNames GetFieldNames() const;
    
    /// Set fieldNames
    void SetFieldNames(FieldNames fieldNames);
    
    /// Get tupleDesc
    Columns::TupleDescPtr GetTupleDescCopy() const;

    /// Set tupleDesc
    void SetTupleDesc(Columns::TupleDescPtr desc);

    /// Get RenameTable
    RenameTable GetRenameTable() const;    

    /// Set RenameTable
    void SetRenameTable(RenameTable renameTable);

    /// Set fieldsNo
    void SetFieldsNo(const std::vector<int>& fieldsNo);

    void SetWithSelectAll();

    bool IsWithSelectAll() const;

public:
    /// ToString func for debug, prefix is the output prefix
    virtual std::string ToString(const std::string& prefix) const = 0;

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