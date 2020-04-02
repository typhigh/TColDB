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

bool ScanPlan::Accept (PlanVisitorPtr visitor, PlanPtr& result)
{
    visitor->VisitPlan(shared_from_this(), result);
}

PlanType_t ScanPlan::GetType() const 
{
    return PLAN_SCAN;
}

Plans ScanPlan::GetChildren()
{
    /// The leaf node in plans-tree
    return {};
}

FieldNames ScanPlan::GetColumnsRef() const 
{
    return {};
}

}