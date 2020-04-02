#include "ProjectPlan.h"
#include "PlanVisitor.h"
using namespace std;

namespace Plan {

void ProjectPlan::SetProjector(Executor::ProjectorPtr projector) 
{
    this->projector = projector;
}

void ProjectPlan::SetProjector(const Parser::ExprNodeList* exprs)
{
    return SetProjector(make_shared<Executor::Projector>(exprs));
}

void ProjectPlan::SetSubPlan(PlanPtr subPlan)
{
    this->subPlan = subPlan;
}

bool ProjectPlan::Accept(PlanVisitorPtr visitor, PlanPtr& result)
{
    visitor->VisitPlan(shared_from_this(), result);
}

PlanType_t ProjectPlan::GetType() const 
{
    return PLAN_PROJECT;
}

Plans ProjectPlan::GetChildren()
{
    return {subPlan};
}

FieldNames ProjectPlan::GetColumnsRef() const 
{
    return projector->GetColumnsRef();
}

}