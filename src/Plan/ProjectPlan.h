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
    std::string ToString(const std::string& prefix) const;
    bool Accept (PlanVisitorPtr visitor, PlanPtr& result);
    PlanType_t GetType() const;
    Plans GetChildren();
    FieldNames GetColumnsRef() const;
};

using ProjectPlanPtr = std::shared_ptr<ProjectPlan>;
}