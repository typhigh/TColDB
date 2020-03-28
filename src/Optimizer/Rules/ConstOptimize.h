#include "Rule.h"

namespace Optimizer {

class ConstOptimize : public Rule
{
private:
    /* data */

public:
    ConstOptimize(/* args */);
    ~ConstOptimize() {}

/// Visit Plan func
public:
    bool VisitPlan(Plan::PlanPtr          plan) const;
    bool VisitPlan(Plan::FilterPlanPtr    plan) const;
    bool VisitPlan(Plan::JoinPlanPtr      plan) const;
};

}