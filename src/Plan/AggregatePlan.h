#pragma once
#include "Plan.h"
#include "../Executor/Aggregator.h"
#include <vector>
namespace Plan {

class AggregatePlan : public Plan, public std::enable_shared_from_this<AggregatePlan>
{
private:
    /* data */
    std::vector<Executor::AggregatorPtr> aggs;
    PlanPtr subPlan;

public:
    AggregatePlan(/* args */) {};
    virtual ~AggregatePlan() {};

public:
    void AddAggregator(Executor::AggregatorPtr agg);
    void AddAggregator(const std::string &fieldName, Parser::operator_type_t aggOp);
    void SetSubPlan(PlanPtr subPlan);

private:
    bool Accept (PlanVisitorPtr rule);
    PlanType_t GetType() const;
};
using AggregatePlanPtr = std::shared_ptr<AggregatePlan>;

}