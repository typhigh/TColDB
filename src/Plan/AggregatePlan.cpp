#include "AggregatePlan.h"
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

void AggregatePlan::AcceptRule(Optimizer::RulePtr rule)
{
    rule->AcceptPlan(*this);
}

}