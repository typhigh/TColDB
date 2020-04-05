#pragma once
#include "Rule.h"
#include "../../Columns/TableID.h"
namespace Optimizer {

struct TableInfo {
    size_t tupleNums;
    Columns::TableID tableID;
    Plan::PlanPtr plan;   
    bool operator < (const TableInfo& other) const {
        return tupleNums < other.tupleNums;
    }
};

class JoinDecompress : public Rule
{
private:
    /* data */
public:
    JoinDecompress() {
        SetName("JoinDecompress");
    }
    ~JoinDecompress();

public:
    bool VisitPlan(Plan::PlanPtr          plan, Plan::PlanPtr& result) const;
    bool VisitPlan(Plan::JoinPlanPtr      plan, Plan::PlanPtr& result) const;
};

}

