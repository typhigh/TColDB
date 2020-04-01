#include "JoinPlan.h"
#include "../Parser/Expression/Expression.h"
#include "PlanVisitor.h"
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

bool JoinPlan::Accept (PlanVisitorPtr visitor)
{
    visitor->VisitPlan(shared_from_this());    
}

PlanType_t JoinPlan::GetType() const 
{
    return PLAN_JOIN;
}

Plans JoinPlan::GetChildren()
{
    return subPlans;
}

}