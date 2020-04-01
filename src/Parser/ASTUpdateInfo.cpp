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
    Plan::PlanPtr ret;
    Plan::ScanPlanPtr lowPlan = Plan::PlansCreator::CreateScanPlan(table, context);
    
    if (where) {
        Plan::FilterPlanPtr filterPlan = Plan::PlansCreator::CreateFilterPlan(context);
        filterPlan->SetPredicator(where);
        
    }
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