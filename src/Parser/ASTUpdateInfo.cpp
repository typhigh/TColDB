#include "ASTUpdateInfo.h"
#include "../Plan/PlansCreator.h"
#include "../Utils/StringUtils.h"

using namespace std;

namespace Parser {

string ASTUpdateInfo::ToString() const 
{
    return "ASTUpdateInfo";
}

Plan::PlanPtr ASTUpdateInfo::MakePlan(Plan::PlanContextPtr context) const 
{
    Plan::PlanPtr lowPlan;
    Plan::ScanPlanPtr plan = Plan::PlansCreator::CreateScanPlan(table, context);
    
    /// First we deal with Where and Table (lowPlan)
    if (where) {
        Plan::FilterPlanPtr filterPlan = Plan::PlansCreator::CreateFilterPlan(context);
        filterPlan->SetPredicator(where);
        filterPlan->SetSubPlan(plan);
        plan->SetParent(filterPlan);
        lowPlan = filterPlan;
    } else {
        lowPlan = plan;
    }
    
    /// Second we deal with UpdatePlan
    Plan::UpdatePlanPtr updatePlan = Plan::PlansCreator::CreateUpdatePlan(column_ref->GetFieldName(), value, context);
    updatePlan->SetSubPlan(lowPlan);
    lowPlan->SetParent(updatePlan);
    return updatePlan;
}

bool ASTUpdateInfo::IsWriteSQL() const
{
    return true;
}

vector<string> ASTUpdateInfo::GetTablesRef() const
{
    return vector<string> {Utils::CopyStringFromCString(table)};
}

}