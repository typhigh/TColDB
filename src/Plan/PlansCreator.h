#pragma once
#include "defs.h"
#include "Plan.h"
#include "AggregatePlan.h"
#include "FilterPlan.h"
#include "JoinPlan.h"
#include "ProjectPlan.h"
#include "ScanPlan.h"

namespace Plan {

class PlansCreator
{
public:
    static AggregatePlanPtr CreateAggregatePlan(PlanContextPtr context);
    static FilterPlanPtr    CreateFilterPlan(PlanContextPtr context);
    static JoinPlanPtr      CreateJoinPlan(PlanContextPtr context);
    static ProjectPlanPtr   CreateProjectPlan(PlanContextPtr context);
    static ScanPlanPtr      CreateScanPlan(Parser::TableFrom* table, PlanContextPtr context);
};


}