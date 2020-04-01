#include "TableMeta.h"
using namespace std;

namespace Columns {

TupleDescPtr TableMeta::GetTupleDesc() const 
{
    /*TODO*/
    return TupleDescPtr();
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

}