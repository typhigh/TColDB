#include "DeletePlan.h"
using namespace std;

namespace Plan {

void DeletePlan::SetSubPlan(PlanPtr subPlan)
{
    this->subPlan = subPlan;
}

bool DeletePlan::Accept(PlanVisitorPtr visitor) 
{
    return visitor->VisitPlan(shared_from_this());
}

PlanType_t DeletePlan::GetType() const 
{
    return PLAN_DELETE;
}

Plans DeletePlan::GetChildren()
{
    return {subPlan};
}

}