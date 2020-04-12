#include "ASTDropTableInfo.h"
using namespace std;

namespace Parser {

ASTDropTableInfo::~ASTDropTableInfo()
{
    delete table;
}

string ASTDropTableInfo::ToString() const 
{
    return "ASTDropTableInfo";
}

bool ASTDropTableInfo::IsWriteSQL() const 
{
    return true;
}

vector<string> ASTDropTableInfo::GetTablesRef() const 
{
    std::string name = table;
    return std::vector<std::string>{name};    
}

void ASTDropTableInfo::Execute(Executor::ExecutorContextPtr context) const 
{
    /*TODO*/
    Columns::TableID tableID = context->GetTableID(GetTablesRef()[0]);
    Columns::TableMetaReadOnlyPtr tableMeta = context->GetTableMeta(tableID);
    
    if (tableMeta == nullptr) {
        context->SubmitResult("No such table");
        return;
    }

    context->SubmitTableMeta(tableID, nullptr);
    context->SubmitResult("Drop done");
}

}
