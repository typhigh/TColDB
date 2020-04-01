#pragma once
#include "Plan.h"
#include "defs.h"
#include "../Executor/Operators/Projector.h"
#include <vector>

namespace Plan {
class ProjectPlan : public Plan, public std::enable_shared_from_this<ProjectPlan>
{
private:
    PlanPtr subPlan;
    Executor::ProjectorPtr projector;
public:
    ProjectPlan(PlanContextPtr context) : Plan(context) {}
    virtual ~ProjectPlan() {}
    void SetProjector(Executor::ProjectorPtr projector);
    void SetProjector(const Parser::ExprNodeList* exprs);
    void SetSubPlan(PlanPtr subPlan);

public:
    bool Accept (PlanVisitorPtr visitor);
    PlanType_t GetType() const;
    Plans GetChildren();
};

using ProjectPlanPtr = std::shared_ptr<ProjectPlan>;
}