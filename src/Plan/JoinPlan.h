#include "Plan.h"
#include "../Parser/ASTExprNode.h"
#include <vector>

namespace Plan {

class JoinPlan : public Plan
{
private:
    std::vector<PlanPtr> subPlans;
    std::shared_ptr<Parser::ASTExprNode> condition;

public:
    JoinPlan(/* args */);
    virtual ~JoinPlan();

    virtual void RuleOptimize(Optimizer::RulePtr rule);
};

using JoinPlanPtr = std::shared_ptr<JoinPlan>;
}