#include "TupleDesc.h"
using namespace std;
namespace Columns {

TupleDescPtr TupleDesc::Clone() const
{
    TupleDescPtr tuple = make_shared<TupleDesc>(*this);
    return tuple;
}

void TupleDesc::SetAlis(string alis) 
{
    for (ColumnDesc& colDesc: desc) {
        colDesc.SetAlis(alis);
    }
}

}