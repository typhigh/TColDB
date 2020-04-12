#include "AggregatePlan.h"
#include "PlanVisitor.h"
using namespace std;

namespace Plan {

void AggregatePlan::SetSubPlan(PlanPtr subPlan) 
{
    this->subPlan = subPlan; 
}

void AggregatePlan::AddAggregator(const string& fieldName, Parser::operator_type_t aggOp)
{
    agg->Add(fieldName, aggOp);
}

string AggregatePlan::ToString(const string& prefix) const
{
    string ret = prefix + "AggregatePlan:\n";
    ret += agg->ToString(prefix);
    ret += desc->ToString(prefix);
    ret += subPlan->ToString(prefix + "  ");
    return ret;
}

bool AggregatePlan::Accept (PlanVisitorPtr visitor, PlanPtr& result)
{
    visitor->VisitPlan(shared_from_this(), result);
}

PlanType_t AggregatePlan::GetType() const 
{
    return PLAN_AGGREGATE;
}

Plans AggregatePlan::GetChildren() 
{
    return {subPlan};
}

FieldNames AggregatePlan::GetColumnsRef() const 
{
    return agg->GetColumnsRef();
}

}