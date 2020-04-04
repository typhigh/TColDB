#include "PlanContext.h"

#include "../Databases/Catalog.h"
#include "../Databases/Database.h"
using namespace std;

namespace Plan {
    
Columns::TupleDescPtr PlanContext::GetTableTupleDesc() const
{
    return context->GetTableTupleDesc();
}

Columns::TupleDescPtr PlanContext::GetTableTupleDesc(Columns::TableID tableID) const
{
    return context->GetTableTupleDesc(tableID);
}

}