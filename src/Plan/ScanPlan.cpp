#include "ScanPlan.h"
#include "../Databases/Database.h"
using namespace std;

namespace Plan {

ScanPlan::ScanPlan(Parser::TableFrom* tableFrom) {
    this->tableName = tableFrom->table;
    Columns::TablePtr table = Databases::Database::GetInstance()->GetCatalog()->GetTable();
    this->desc = table->GetCurrentMeta()->GetTupleDesc()->Clone();
    if (tableFrom->alias) {
        
    }
}

}