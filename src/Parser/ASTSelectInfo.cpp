#include "ASTSelectInfo.h"
#include "../Plan/PlansCreator.h"
#include "../Plan/JoinPlan.h"
#include "../Plan/ScanPlan.h"
#include "../Plan/AggregatePlan.h"
#include "../Plan/FilterPlan.h"
#include "../Plan/ProjectPlan.h"
#include "Expression/Expression.h"
#include "../Utils/StringUtils.h"
using namespace std;

namespace Parser {

ASTSelectInfo::~ASTSelectInfo()
{
    if (tables != nullptr) {
        for (TableFrom* ele: *tables) {
            delete ele;
        }
        delete tables;
    }

    Expression::Free(exprs);
    Expression::Free(where);
}

string ASTSelectInfo::ToString() const 
{
    return "ASTSelectInfo";
}

Plan::PlanPtr ASTSelectInfo::MakePlan(Plan::PlanContextPtr planContext) const 
{
    Plan::PlanPtr ret;
    ret->SetPlanContext(planContext);

    // First we deal with Where and Table (LowPLan)
    Plan::PlanPtr LowPlan;
    if (tables == nullptr) {
        LOG_ERROR("expected not null table");
        return nullptr;
    }

    if (tables->size() > 1) {
        // JoinPlan
        Plan::JoinPlanPtr plan = Plan::PlansCreator::CreateJoinPlan();
        plan->SetPlanContext(planContext);
        plan->SetCondition(where);
        for (size_t i = 0; i < tables->size(); ++i)  {
            Plan::PlanPtr subPlan = Plan::PlansCreator::CreateScanPlan(tables->at(i));
            subPlan->SetPlanContext(planContext);
            plan->AddSubPlan(subPlan);
            subPlan->SetParent(plan);
        }
        LowPlan = plan;
    } else {
        Plan::ScanPlanPtr plan = Plan::PlansCreator::CreateScanPlan(tables->at(0));
        plan->SetPlanContext(planContext);
        if (where) {
            // FilterPlan
            Plan::FilterPlanPtr filterPlan = Plan::PlansCreator::CreateFilterPlan();
            filterPlan->SetPlanContext(planContext);
            filterPlan->SetPredicator(where);
            filterPlan->SetSubPlan(plan);
            plan->SetParent(filterPlan);
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
        plan->SetPlanContext(planContext);
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
        plan->SetPlanContext(planContext);
        plan->SetProjector(exprs);
        plan->SetSubPlan(LowPlan);
        ret = plan;
    }
    return ret;
}

bool ASTSelectInfo::IsWriteSQL() const
{
    return false;
}

vector<string> ASTSelectInfo::GetTablesRef() const
{
    vector<string> ret;
    for (const TableFrom* table: *tables) {
        ret.push_back(table->GetTableRef());
    }
    return ret;
}

}