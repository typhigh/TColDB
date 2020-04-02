#pragma once
#include "defs.h"
#include "Plan.h"
#include "../Parser/ExprNode.h"
#include "../Executor/Operators/Predicator.h"
#include <vector>

namespace Plan {

class JoinPlan : public Plan, public std::enable_shared_from_this<JoinPlan>
{
private:
    std::vector<PlanPtr> subPlans;
    Executor::PredicatorPtr predicator;

public:
    JoinPlan(PlanContextPtr context) : Plan(context) {}

    void SetSubPlans(const std::vector<PlanPtr> &subPlans);
    void AddSubPlan(PlanPtr subPlan);
    void SetPredicator(Parser::ExprNode* expr);
    virtual ~JoinPlan() {}

public:
    bool Accept (PlanVisitorPtr visitor, PlanPtr& result);
    PlanType_t GetType() const;
    Plans GetChildren();
    FieldNames GetColumnsRef() const;
};

using JoinPlanPtr = std::shared_ptr<JoinPlan>;
}