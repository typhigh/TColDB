#include "PlansCreator.h"
using namespace std;

namespace Plan {

AggregatePlanPtr PlansCreator::CreateAggregatePlan(PlanContextPtr context)
{
    return make_shared<AggregatePlan>(context);
}

DeletePlanPtr PlansCreator::CreateDeletePlan(PlanContextPtr context)
{
    return make_shared<DeletePlan>(context);
}

FilterPlanPtr PlansCreator::CreateFilterPlan(PlanContextPtr context)
{
    return make_shared<FilterPlan>(context);
}

JoinPlanPtr PlansCreator::CreateJoinPlan(PlanContextPtr context)
{
    return make_shared<JoinPlan>(context);
}

ProjectPlanPtr PlansCreator::CreateProjectPlan(PlanContextPtr context)
{
    return make_shared<ProjectPlan>(context);
}

ScanPlanPtr PlansCreator::CreateScanPlan(Parser::TableFrom* table, PlanContextPtr context)
{
    return make_shared<ScanPlan>(table, context);
}

ScanPlanPtr PlansCreator::CreateScanPlan(char* tableName, PlanContextPtr context)
{
    return make_shared<ScanPlan>(tableName, context);
}

UpdatePlanPtr PlansCreator::CreateUpdatePlan(const std::string& fieldName, Parser::ExprNode* value, PlanContextPtr context) 
{
    return make_shared<UpdatePlan>(fieldName, value, context);
}

}