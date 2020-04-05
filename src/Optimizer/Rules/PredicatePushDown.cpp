#include "PredicatePushDown.h"
using namespace std;
using namespace Plan;

namespace Optimizer {

bool PredicatePushDown::VisitPlan(PlanPtr plan, PlanPtr& result) const
{
    return false;
}

bool PredicatePushDown::VisitPlan(FilterPlanPtr plan, PlanPtr& result) const
{
    Plans children = plan->GetChildren();
    if (children.size() == 1) {
        PlanPtr child = children[0];
    } else if (children.size() > 1) {

    }                                                                                                           
} 

bool PredicatePushDown::VisitPlan(JoinPlanPtr plan, PlanPtr& result) const 
{
    /*TODO*/
}

}