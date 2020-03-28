#include "PlansCreator.h"
using namespace std;

namespace Plan {

AggregatePlanPtr PlansCreator::CreateAggregatePlan()
{
    return make_shared<AggregatePlan>();
}
FilterPlanPtr PlansCreator::CreateFilterPlan()
{
    return make_shared<FilterPlan>();
}

JoinPlanPtr PlansCreator::CreateJoinPlan()
{
    return make_shared<JoinPlan>();
}

ProjectPlanPtr PlansCreator::CreateProjectPlan()
{
    return make_shared<ProjectPlan>();
}

ScanPlanPtr PlansCreator::CreateScanPlan()
{
    return make_shared<ScanPlan>();
}

ScanPlanPtr PlansCreator::CreateScanPlan(Parser::TableFrom* table)
{
    return make_shared<ScanPlan>(table);
}

}