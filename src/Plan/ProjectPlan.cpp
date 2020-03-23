#include "ProjectPlan.h"
#include "../Optimizer/Rules/Rule.h"
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

void ProjectPlan::AcceptRule(Optimizer::RulePtr rule)
{
    rule->AcceptPlan(*this);
}
}