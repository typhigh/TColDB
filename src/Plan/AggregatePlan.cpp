#include "AggregatePlan.h"
#include "PlanVisitor.h"
using namespace std;

namespace Plan {

void AggregatePlan::SetSubPlan(PlanPtr subPlan) 
{
    this->subPlan = subPlan; 
}

void AggregatePlan::AddAggregator(Executor::AggregatorPtr agg)
{
    aggs.push_back(agg);
}

void AggregatePlan::AddAggregator(const string& fieldName, Parser::operator_type_t aggOp)
{
    return AddAggregator(
        make_shared <Executor::Aggregator>(
            fieldName,
            aggOp
        )
    );
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
    FieldNames ret;
    for (auto agg : aggs) {    
        ret.push_back(move(agg->GetFieldName()));
    }
    return 
}

}