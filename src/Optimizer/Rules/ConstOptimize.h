#include "Rule.h"

namespace Optimizer {

class ConstOptimize : public Rule
{
public:
    ConstOptimize() {}
    ~ConstOptimize() {}

/// Visit Plan func
public:
    bool VisitPlan(Plan::PlanPtr          plan, Plan::PlanPtr& result) const;
    bool VisitPlan(Plan::FilterPlanPtr    plan, Plan::PlanPtr& result) const;
    bool VisitPlan(Plan::JoinPlanPtr      plan, Plan::PlanPtr& result) const;
};

using ConstOptimizePtr = std::shared_ptr<ConstOptimize>;
ConstOptimizePtr constOptimize = std::make_shared<ConstOptimize>();
}