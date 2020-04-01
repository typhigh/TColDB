#include "ScanPlan.h"
#include "PlanVisitor.h"
using namespace std;

namespace Plan {

ScanPlan::ScanPlan(Parser::TableFrom* tableFrom, PlanContextPtr context) : Plan(context) {
    this->tableName = tableFrom->table;
    this->desc = this->context->GetTableTupleDesc(tableFrom->table);
    if (tableFrom->alias) {
        desc->SetAlis(tableFrom->alias);
    }
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