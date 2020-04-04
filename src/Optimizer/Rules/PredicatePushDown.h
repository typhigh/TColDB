#pragma once
#include "Rule.h"

namespace Optimizer {

class PredicatePushDown : public Rule
{
public:
    PredicatePushDown() {}
    ~PredicatePushDown() {}

public:
    bool VisitPlan(Plan::PlanPtr          plan, Plan::PlanPtr& result) const;
    bool VisitPlan(Plan::FilterPlanPtr    plan, Plan::PlanPtr& result) const;
    bool VisitPlan(Plan::JoinPlanPtr      plan, Plan::PlanPtr& result) const;
};

using PredicatePushDownPtr = std::shared_ptr<PredicatePushDown>;
PredicatePushDownPtr predicatePushDown = std::make_shared<PredicatePushDown>();
}