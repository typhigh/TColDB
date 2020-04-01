#include "UpdatePlan.h"
using namespace std;

namespace Plan {

UpdatePlan::UpdatePlan(const std::string& fieldName, Parser::ExprNode* value, PlanContextPtr context)
    : Plan(context)
    , fieldName(fieldName)
{
    updator = make_shared<Executor::Updator>(value);
}

void UpdatePlan::SetSubPlan(PlanPtr subPlan)
{
    this->subPlan = subPlan;
}

bool UpdatePlan::Accept(PlanVisitorPtr visitor)
{
    visitor->VisitPlan(shared_from_this());
}

PlanType_t UpdatePlan::GetType() const
{
    return PLAN_UPDATE;
}

Plans UpdatePlan::GetChildren()
{
    return {subPlan};
}

}