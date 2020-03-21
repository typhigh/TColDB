#include "ASTSelectInfo.h"
#include "../Plan/JoinPlan.h"
#include "../Plan/ScanPlan.h"
using namespace std;

namespace Parser {
string ASTSelectInfo::ToString() const 
{
    return "ASTSelectInfo";
}

Plan::PlanPtr ASTSelectInfo::MakePlan() const 
{
    Plan::PlanPtr ret;
    if (tables->size() > 1) {
        // JoinPlan
        Plan::JoinPlanPtr plan = Plan::JoinPlanPtr();
        plan->SetCondition(where);
        for (size_t i = 0; i < this->tables->size(); ++i)  {
            Plan::PlanPtr subPlan = Plan::ScanPlanPtr(this->tables->at(i));
            plan->AddSubPlan(subPlan);
        }
    } else {
        // SelectPlan
        
    }
    

    return Plan::PlanPtr();
}

}