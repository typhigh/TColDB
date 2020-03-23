#include "FilterPlan.h"
#include "../Optimizer/Rules/Rule.h"
using namespace std;

namespace Plan {

void FilterPlan::SetPredicator(Executor::PredicatorPtr predicator)
{
    this->predicator = predicator;
}

void FilterPlan::SetPredicator(Parser::ExprNode* cond)
{
    return SetPredicator(make_shared<Executor::Predicator>(cond));
}

void FilterPlan::SetSubPlan(PlanPtr subPlan) 
{
    this->subPlan = subPlan;
}

void FilterPlan::AcceptRule(Optimizer::RulePtr rule)
{
    rule->AcceptPlan(*this);
}
}