#include "ScanPlan.h"
#include "PlanVisitor.h"
using namespace std;

namespace Plan {

ScanPlan::ScanPlan(Parser::TableFrom* tableFrom, PlanContextPtr context) 
    : ScanPlan(tableFrom->table, context)
{
    if (tableFrom->alias) {
        RenameTable rename;
        rename.Set(tableName, tableFrom->alias);
        SetRenameTable(rename);
        desc->SetAlis(GetRenameTable());
    }
}

ScanPlan::ScanPlan(char* tableName, PlanContextPtr context)
    : Plan(context)
    , tableName(tableName)
{
    this->tableID = context->GetTableID(tableName);
    this->desc = context->GetTableTupleDesc(tableID);
}

string ScanPlan::GetTableName() const 
{
    return tableName;
}

std::string ScanPlan::ToString(const string& prefix) const
{
    string ret = prefix + "ScanPlan:\n";
    ret += desc->ToString(prefix);
    return ret;
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