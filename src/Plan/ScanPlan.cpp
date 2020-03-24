#include "ScanPlan.h"
#include "../Databases/Database.h"
using namespace std;

namespace Plan {

ScanPlan::ScanPlan(Parser::TableFrom* tableFrom) {
    this->tableName = tableFrom->table;
    this->desc = this->planContext->GetTableMeta(tableName)->GetTupleDesc();
    if (tableFrom->alias) {
        desc->SetAlis(tableFrom->alias);
    }
}

void ScanPlan::AcceptRule(Optimizer::RulePtr rule) 
{
    rule->AcceptPlan(*this);
}

}