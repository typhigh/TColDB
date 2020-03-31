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

bool FilterPlan::Accept(PlanVisitorPtr visitor)
{
    visitor->VisitPlan(shared_from_this());
}

PlanType_t FilterPlan::GetType() const 
{
    return PLAN_FILTER;
}

}