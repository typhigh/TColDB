#include "DeletePlan.h"
using namespace std;

namespace Plan {

void DeletePlan::SetSubPlan(PlanPtr subPlan)
{
    this->subPlan = subPlan;
}

bool DeletePlan::Accept(PlanVisitorPtr visitor, PlanPtr& result) 
{
    return visitor->VisitPlan(shared_from_this(), result);
}

PlanType_t DeletePlan::GetType() const 
{
    return PLAN_DELETE;
}

Plans DeletePlan::GetChildren()
{
    return {subPlan};
}

FieldNames DeletePlan::GetColumnsRef() const 
{
    return {};
}

}