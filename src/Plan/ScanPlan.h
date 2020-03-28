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
    Columns::TupleDescPtr desc;
    // helper
    std::vector<int> columns;
    
public:
    ScanPlan() {}
    ScanPlan(Parser::TableFrom* tableFrom);
    virtual ~ScanPlan() {}

public:
    bool Accept (PlanVisitorPtr visitor);
    PlanType_t GetType() const;
};

using ScanPlanPtr = std::shared_ptr<ScanPlan>;
}