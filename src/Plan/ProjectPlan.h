#pragma once
#include "Plan.h"
#include "defs.h"
#include "../Executor/Projector.h"
#include <vector>

namespace Plan {
class ProjectPlan : public Plan
{
private:
    PlanPtr subPlan;
    Executor::ProjectorPtr projector;
public:
    ProjectPlan(/* args */) {}
    virtual ~ProjectPlan() {}
    void SetProjector(Executor::ProjectorPtr projector);
    void SetProjector(const Parser::ExprNodeList* exprs);
    void SetSubPlan(PlanPtr subPlan);

private:
    void AcceptRule (Optimizer::RulePtr rule);
};

using ProjectPlanPtr = std::shared_ptr<ProjectPlan>;
}