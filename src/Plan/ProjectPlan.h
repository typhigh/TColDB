#include "Plan.h"
#include <vector>

namespace Plan {
class ProjectPlan : public Plan
{
private:
    PlanPtr subPlan;
    std::vector<int> fields;
    
public:
    ProjectPlan(/* args */);
    virtual ~ProjectPlan();

    virtual void RuleOptimize (Optimizer::RulePtr rule);
};

using ProjectPlanPtr = std::shared_ptr<ProjectPlan>;
}