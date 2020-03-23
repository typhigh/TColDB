#pragma once
#include "defs.h"
#include "Plan.h"
#include "../Parser/ExprNode.h"
#include <vector>

namespace Plan {

class JoinPlan : public Plan
{
private:
    std::vector<PlanPtr> subPlans;
    std::shared_ptr<Parser::ExprNode*> condition;

public:
    JoinPlan(/* args */) {}

    void SetSubPlans(const std::vector<PlanPtr> &subPlans);
    void AddSubPlan(PlanPtr subPlan);
    void SetCondition(Parser::ExprNode* expr);
//    std::vector<PlanPtr> GetSubPlans() const;
    virtual ~JoinPlan() {}

private:
    void AcceptRule(Optimizer::RulePtr rule);
};

using JoinPlanPtr = std::shared_ptr<JoinPlan>;
}