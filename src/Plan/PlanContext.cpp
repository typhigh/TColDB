#include "PlanContext.h"

#include "../Databases/Catalog.h"
#include "../Databases/Database.h"
using namespace std;

namespace Plan {

Columns::TableID PlanContext::GetTableID(const string& tableName) const 
{
    return context->GetTableID(tableName);
}

Columns::TupleDescPtr PlanContext::GetTableTupleDesc(Columns::TableID tableID) const
{
    return context->GetTableTupleDesc(tableID);
}

size_t PlanContext::GetTupleCount(Columns::TableID tableID) const 
{
    return context->GetTupleCount(tableID);
}

}