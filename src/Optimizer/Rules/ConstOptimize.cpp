#include "ConstOptimize.h"
#include "../../Parser/Expression/Expression.h"
using namespace std;
using namespace Plan;

namespace Optimizer {

bool ConstOptimize::VisitPlan(FilterPlanPtr plan, PlanPtr& result) const
{   
    Parser::ExprNodeList* expr = plan->GetPredicator()->Get();
    Parser::Expression::ConstOptimize(expr);
    return true;
}

bool ConstOptimize::VisitPlan(JoinPlanPtr plan, PlanPtr& result) const
{
    /*TODO*/
    return true;    
}


}