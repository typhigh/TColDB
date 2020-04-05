#pragma once
#include "Rule.h"

namespace Optimizer {

class ConstOptimize : public Rule
{
public:
    ConstOptimize() {
        SetName("ConstOptimize");
    }
    ~ConstOptimize() {}

/// Visit Plan func
public:
    bool VisitPlan(Plan::FilterPlanPtr    plan, Plan::PlanPtr& result) const;
    bool VisitPlan(Plan::JoinPlanPtr      plan, Plan::PlanPtr& result) const;
};

using ConstOptimizePtr = std::shared_ptr<ConstOptimize>;

}