#include "ASTShowTableInfo.h"
using namespace std;

namespace Parser {
    
string ASTShowTableInfo::ToString() const 
{
    return "ASTShowTableInfo";
}

bool ASTShowTableInfo::IsWriteSQL() const 
{
    return false;
}

std::vector<std::string> ASTShowTableInfo::GetTablesRef() const 
{
    std::string name = table;
    return std::vector<std::string>{name};
}

void ASTShowTableInfo::Execute(Executor::ExecutorContextPtr context) const 
{
    Columns::TableID tableID = context->GetTableID(table);
    Columns::TableMetaReadOnlyPtr tableMeta = context->GetTableMeta(tableID);
    
    /// Check if the table is not exisit
    if (tableMeta == nullptr) {
        LOG_DEBUG("There is no such table");
        context->SubmitResult("No such table");
        return;
    } 

    context->SubmitResult(tableMeta->ToString());
}

}