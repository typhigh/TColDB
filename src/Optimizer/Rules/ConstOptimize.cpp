#include "ConstOptimize.h"
#include "../../Parser/Expression/Expression.h"
using namespace std;

namespace Optimizer {

bool ConstOptimize::VisitPlan(Plan::PlanPtr plan) const 
{
    return false;
}

bool ConstOptimize::VisitPlan(Plan::FilterPlanPtr plan) const
{   
    Parser::ExprNode* expr = plan->GetPredicator()->cond;
    Parser::Expression::ConstOptimize(expr);
    return true;
}

bool ConstOptimize::VisitPlan(Plan::JoinPlanPtr plan) const
{
    /*TODO*/
    return true;    
}


}