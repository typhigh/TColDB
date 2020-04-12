#pragma once
#include "Plan.h"
#include "defs.h"
#include "../Columns/TupleDesc.h"
#include "../Parser/TableFrom.h"
#include <vector>
#include <string>
namespace Plan {

class ScanPlan : public Plan, public std::enable_shared_from_this<ScanPlan>
{
private:
    /* data */
    std::string tableName;
    Columns::TableID tableID;
    // helper
    std::vector<int> columns;
    
public:
    ScanPlan(char* name, PlanContextPtr context);
    ScanPlan(Parser::TableFrom* tableFrom, PlanContextPtr context);
    virtual ~ScanPlan() {}
    std::string GetTableName() const;

public:
    std::string ToString(const std::string& prefix) const;
    bool Accept (PlanVisitorPtr visitor, PlanPtr& result);
    PlanType_t GetType() const;
    Plans GetChildren();
    FieldNames GetColumnsRef() const;
};

using ScanPlanPtr = std::shared_ptr<ScanPlan>;
}