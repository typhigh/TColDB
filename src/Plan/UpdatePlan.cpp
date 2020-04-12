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

string UpdatePlan::ToString(const string& prefix) const 
{
    string ret = prefix + "UpdatePlan:\n";
    ret += desc->ToString("");
    ret += subPlan->ToString(prefix + "  ");
    return ret;
}

bool UpdatePlan::Accept(PlanVisitorPtr visitor, PlanPtr& result)
{
    visitor->VisitPlan(shared_from_this(), result);
}

PlanType_t UpdatePlan::GetType() const
{
    return PLAN_UPDATE;
}

Plans UpdatePlan::GetChildren()
{
    return {subPlan};
}

FieldNames UpdatePlan::GetColumnsRef() const 
{
    return updator->GetColumnsRef();
}

}