#include "TableMeta.h"
using namespace std;

namespace Columns {

TupleDescPtr TableMeta::GetTupleDescCopy() const 
{
    return tupleDesc->Clone();
}

string TableMeta::GetTableName() const 
{
    return tabelName;
}

FieldPtr TableMeta::GetField(RowID rid, ColID cid) const 
{
    /*TODO*/
    return nullptr;
}

size_t TableMeta::GetTupleCount() const 
{
    /*TODO*/
    
}

}