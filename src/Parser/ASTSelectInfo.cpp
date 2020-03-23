#include "ASTSelectInfo.h"
#include "../Plan/JoinPlan.h"
#include "../Plan/ScanPlan.h"
#include "../Plan/AggregatePlan.h"
#include "../Plan/FilterPlan.h"
#include "../Plan/ProjectPlan.h"
#include "Expression/Expression.h"
#include "../Utils/StringUtils.h"
using namespace std;

namespace Parser {
string ASTSelectInfo::ToString() const 
{
    return "ASTSelectInfo";
}

Plan::PlanPtr ASTSelectInfo::MakePlan() const 
{
    Plan::PlanPtr ret;

    // First we deal with Where and Table (LowPLan)
    Plan::PlanPtr LowPlan;
    if (tables == NULL) {
        LOG_ERROR("expected not null table");
        return ret;
    }
    if (tables->size() > 1) {
        // JoinPlan
        Plan::JoinPlanPtr plan = make_shared<Plan::JoinPlan>();
        plan->SetCondition(where);
        for (size_t i = 0; i < tables->size(); ++i)  {
            Plan::PlanPtr subPlan = make_shared<Plan::ScanPlan>(tables->at(i));
            plan->AddSubPlan(subPlan);
        }
        LowPlan = plan;
    } else {
        Plan::ScanPlanPtr plan = make_shared<Plan::ScanPlan>(tables->at(0));
        if (where) {
            // FilterPlan
            Plan::FilterPlanPtr filterPlan = make_shared<Plan::FilterPlan>();
            filterPlan->SetPredicator(where);
            filterPlan->SetSubPlan(plan);
            LowPlan = filterPlan;
        } else {
            // ScanPlan
            LowPlan = plan;
        }
    }
    
    // Second we deal with SelectList (exprs) (ret)
    if (exprs == NULL) {
        // ScanPlan
        ret = LowPlan;
    } else if (Expression::IsAggregate(exprs)) {
        // AggregatePlan
        Plan::AggregatePlanPtr plan = make_shared<Plan::AggregatePlan>();
        for (const ExprNode* expr: *exprs) {
            if (Expression::IsAggregate(expr)) {
                // We only consider aggregate expr and ignore other expr
                plan->AddAggregator(
                    expr->column_ref->GetFieldName(),
                    expr->op
                );
            }
        }
        plan->SetSubPlan(LowPlan);
        ret = plan;
    } else {
        // ProjectPlan
        Plan::ProjectPlanPtr plan = make_shared<Plan::ProjectPlan>();
        plan->SetProjector(exprs);
        plan->SetSubPlan(LowPlan);
        ret = plan;
    }
    return ret;
}

}