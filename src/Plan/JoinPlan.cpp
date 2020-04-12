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

void JoinPlan::SetPredicator(Parser::ExprNode* expr) 
{
    predicator = make_shared<Executor::Predicator>(expr);
}

string JoinPlan::ToString(const string& prefix) const 
{
    string ret = prefix + "JoinPlan:\n";
    ret += predicator->ToString(prefix);
    ret += desc->ToString(prefix);
    for (auto plan: subPlans) {
        ret += plan->ToString(prefix + "  ");
    }
    return ret;
}

bool JoinPlan::Accept (PlanVisitorPtr visitor, PlanPtr& result)
{
    visitor->VisitPlan(shared_from_this(), result);    
}

PlanType_t JoinPlan::GetType() const 
{
    return PLAN_JOIN;
}

Plans JoinPlan::GetChildren()
{
    return subPlans;
}

FieldNames JoinPlan::GetColumnsRef() const 
{
    return predicator->GetColumnsRef();
}

}