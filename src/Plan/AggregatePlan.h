#pragma once
#include "Plan.h"
#include "../Executor/Operators/Aggregator.h"
#include <vector>
namespace Plan {

class AggregatePlan : public Plan, public std::enable_shared_from_this<AggregatePlan>
{
private:
    /* data */
    Executor::AggregatorPtr agg = std::make_shared<Executor::Aggregator>();
    PlanPtr subPlan;

public:
    AggregatePlan(PlanContextPtr context) : Plan(context) {};
    virtual ~AggregatePlan() {};

public:
    void AddAggregator(const std::string &fieldName, Parser::operator_type_t aggOp);
    void SetSubPlan(PlanPtr subPlan);

private:
    std::string ToString(const std::string& prefix) const;
    bool Accept (PlanVisitorPtr rule, PlanPtr& result);
    PlanType_t GetType() const;
    Plans GetChildren();
    virtual FieldNames GetColumnsRef() const;
};

using AggregatePlanPtr = std::shared_ptr<AggregatePlan>;

}