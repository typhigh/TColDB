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

Plan::PlanPtr ASTSelectInfo::MakePlan(Plan::PlanContextPtr context) const 
{
    Plan::PlanPtr ret;

    /// First we deal with Where and Table (lowPlan)
    Plan::PlanPtr lowPlan;
    if (tables == nullptr) {
        LOG_ERROR("expected not null table");
        return nullptr;
    }

    if (tables->size() > 1) {
        /// JoinPlan
        Plan::JoinPlanPtr plan = Plan::PlansCreator::CreateJoinPlan(context);
        plan->SetCondition(where);
        for (size_t i = 0; i < tables->size(); ++i)  {
            Plan::PlanPtr subPlan = Plan::PlansCreator::CreateScanPlan(tables->at(i), context);
            plan->AddSubPlan(subPlan);
            subPlan->SetParent(plan);
        }
        lowPlan = plan;
    } else {
        Plan::ScanPlanPtr plan = Plan::PlansCreator::CreateScanPlan(tables->at(0), context);
        if (where) {
            /// FilterPlan
            Plan::FilterPlanPtr filterPlan = Plan::PlansCreator::CreateFilterPlan(context);
            filterPlan->SetPredicator(where);
            filterPlan->SetSubPlan(plan);
            plan->SetParent(filterPlan);
            lowPlan = filterPlan;
        } else {
            /// ScanPlan
            lowPlan = plan;
        }
    }
    
    /// Second we deal with SelectList (exprs) (ret)
    if (exprs == NULL) {
        /// ScanPlan
        ret = lowPlan;
    } else if (Expression::IsAggregate(exprs)) {
        /// AggregatePlan
        Plan::AggregatePlanPtr plan = make_shared<Plan::AggregatePlan>(context);
        for (const ExprNode* expr: *exprs) {
            if (Expression::IsAggregate(expr)) {
                /// We only consider aggregate expr and ignore other expr
                plan->AddAggregator(
                    expr->column_ref->GetFieldName(),
                    expr->op
                );
            }
        }
        plan->SetSubPlan(lowPlan);
        ret = plan;
    } else {
        /// ProjectPlan
        Plan::ProjectPlanPtr plan = make_shared<Plan::ProjectPlan>(context);
        plan->SetProjector(exprs);
        plan->SetSubPlan(lowPlan);
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