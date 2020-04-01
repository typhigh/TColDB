#pragma once
#include "defs.h"
#include "Plan.h"
#include "../Parser/ExprNode.h"
#include <vector>

namespace Plan {

class JoinPlan : public Plan, public std::enable_shared_from_this<JoinPlan>
{
private:
    std::vector<PlanPtr> subPlans;
    std::shared_ptr<Parser::ExprNode*> condition;

public:
    JoinPlan(PlanContextPtr context) : Plan(context) {}

    void SetSubPlans(const std::vector<PlanPtr> &subPlans);
    void AddSubPlan(PlanPtr subPlan);
    void SetCondition(Parser::ExprNode* expr);
//    std::vector<PlanPtr> GetSubPlans() const;
    virtual ~JoinPlan() {}

public:
    bool Accept (PlanVisitorPtr visitor);
    PlanType_t GetType() const;
};

using JoinPlanPtr = std::shared_ptr<JoinPlan>;
}