#include "JoinPlan.h"
#include "../Parser/Expression/Expression.h"
using namespace std;
namespace Plan {

void JoinPlan::SetSubPlans(const vector<PlanPtr>& subPlans)
{
    this->subPlans = subPlans;
}

void JoinPlan::AddSubPlan(PlanPtr subPlan) 
{
    subPlans.push_back(subPlan);
}

void JoinPlan::SetCondition(Parser::ExprNode* expr) 
{
    condition = make_shared<Parser::ExprNode*>();
}

void JoinPlan::AcceptRule(Optimizer::RulePtr rule) 
{
    rule->AcceptPlan(*this);    
}

}