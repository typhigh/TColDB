#include "ScanPlan.h"
#include "PlanVisitor.h"
using namespace std;

namespace Plan {

ScanPlan::ScanPlan(Parser::TableFrom* tableFrom, PlanContextPtr context) 
    : ScanPlan(tableFrom->table, context)
{
    if (tableFrom->alias) {
        desc->SetAlis(tableFrom->alias);
    }
}

ScanPlan::ScanPlan(char* tableName, PlanContextPtr context)
    : Plan(context)
    , tableName(tableName)
{
    
}

bool ScanPlan::Accept (PlanVisitorPtr visitor)
{
    visitor->VisitPlan(shared_from_this());
}

PlanType_t ScanPlan::GetType() const 
{
    return PLAN_SCAN;
}

}