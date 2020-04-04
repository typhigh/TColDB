#include "ASTDeleteInfo.h"
#include "../Plan/PlansCreator.h"
#include "../Utils/StringUtils.h"
#include "Expression/Expression.h"
using namespace std;
namespace Parser {

ASTDeleteInfo::~ASTDeleteInfo() 
{  
    delete table;
    Expression::Free(where);
}

string ASTDeleteInfo::ToString() const 
{
    return "ASTDeleteInfo";
}

Plan::PlanPtr ASTDeleteInfo::MakePlan(Plan::PlanContextPtr context) const 
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

    /// Second we deal with DeletePlan
    Plan::DeletePlanPtr deletePlan = Plan::PlansCreator::CreateDeletePlan(context);
    deletePlan->SetSubPlan(lowPlan);
    lowPlan->SetParent(deletePlan);
    deletePlan->SetWithSelectAll();
    return deletePlan;
}

bool ASTDeleteInfo::IsWriteSQL() const
{
    return true;
}

vector<string> ASTDeleteInfo::GetTablesRef() const
{
    return vector<string> {Utils::CopyStringFromCString(table)};
}

}