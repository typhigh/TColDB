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
    static AggregatePlanPtr CreateAggregatePlan();
    static FilterPlanPtr    CreateFilterPlan();
    static JoinPlanPtr      CreateJoinPlan();
    static ProjectPlanPtr   CreateProjectPlan();
    static ScanPlanPtr      CreateScanPlan();
    static ScanPlanPtr      CreateScanPlan(Parser::TableFrom* table);
};


}