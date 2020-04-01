#include "PlanContext.h"

#include "../Databases/Catalog.h"
#include "../Databases/Database.h"
using namespace std;

namespace Plan {

Columns::FieldPtr PlanContext::FetchField(Columns::RowID rid, Columns::ColID cid) const
{
    return context->FetchField(rid, cid);
}

Columns::FieldPtr PlanContext::FetchField(const std::string& tableName, Columns::RowID rid, Columns::ColID cid) const
{
    return context->FetchField(tableName, rid, cid);
}
    
Columns::TupleDescPtr PlanContext::GetTableTupleDesc() const
{
    return context->GetTableTupleDesc();
}

Columns::TupleDescPtr PlanContext::GetTableTupleDesc(const std::string& tableName) const
{
    return context->GetTableTupleDesc(tableName);
}

}