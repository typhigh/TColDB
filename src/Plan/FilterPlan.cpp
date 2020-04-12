#include "FilterPlan.h"
using namespace std;

namespace Plan {

void FilterPlan::SetPredicator(Executor::PredicatorPtr predicator)
{
    this->predicator = predicator;
}

void FilterPlan::SetPredicator(Parser::ExprNode* cond)
{
    return SetPredicator(make_shared<Executor::Predicator>(cond));
}

void FilterPlan::SetSubPlan(PlanPtr subPlan) 
{
    this->subPlan = subPlan;
}

Executor::PredicatorPtr FilterPlan::GetPredicator()
{
    return predicator;
}

std::string FilterPlan::ToString(const std::string& prefix) const 
{
    string ret = prefix + "FilterPlan:\n";
    ret += predicator->ToString(prefix);
    ret += desc->ToString(prefix);
    ret += subPlan->ToString(prefix + "  ");
    return ret;
}

bool FilterPlan::Accept(PlanVisitorPtr visitor, PlanPtr& result)
{
    visitor->VisitPlan(shared_from_this(), result);
}

PlanType_t FilterPlan::GetType() const 
{
    return PLAN_FILTER;
}

Plans FilterPlan::GetChildren()
{
    return {subPlan};
}

FieldNames FilterPlan::GetColumnsRef() const 
{
    return this->predicator->GetColumnsRef();
}

}