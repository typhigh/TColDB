#pragma once
#include "Plan.h"
#include "../Executor/Aggregator.h"
#include <vector>
namespace Plan {

class AggregatePlan : public Plan
{
private:
    /* data */
    std::vector<Executor::AggregatorPtr> aggs;
    PlanPtr subPlan;

public:
    AggregatePlan(/* args */) {};
    virtual ~AggregatePlan() {};

private:
    void AcceptRule (Optimizer::RulePtr rule) ;

public:
    void AddAggregator(Executor::AggregatorPtr agg);
    void AddAggregator(const std::string &fieldName, Parser::operator_type_t aggOp);
    void SetSubPlan(PlanPtr subPlan);
};
using AggregatePlanPtr = std::shared_ptr<AggregatePlan>;

}