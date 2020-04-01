#pragma once
#include "defs.h"
#include "Plan.h"
#include "AggregatePlan.h"
#include "DeletePlan.h"
#include "FilterPlan.h"
#include "JoinPlan.h"
#include "ProjectPlan.h"
#include "ScanPlan.h"
#include "UpdatePlan.h"
#include "../Parser/ExprNode.h"

namespace Plan {

class PlansCreator
{
public:
    static AggregatePlanPtr CreateAggregatePlan(PlanContextPtr context);
    static DeletePlanPtr    CreateDeletePlan(PlanContextPtr context);
    static FilterPlanPtr    CreateFilterPlan(PlanContextPtr context);
    static JoinPlanPtr      CreateJoinPlan(PlanContextPtr context);
    static ProjectPlanPtr   CreateProjectPlan(PlanContextPtr context);
    static ScanPlanPtr      CreateScanPlan(Parser::TableFrom* table, PlanContextPtr context);
    static ScanPlanPtr      CreateScanPlan(char* table, PlanContextPtr context); 
    static UpdatePlanPtr    CreateUpdatePlan(const std::string& fieldName, Parser::ExprNode* value, PlanContextPtr context);
};


}