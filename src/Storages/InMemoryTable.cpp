#include "InMemoryTable.h"
using namespace std;
using namespace Columns;

namespace Storages {

void InMemoryTable::Clear()
{
    tuples.clear();
    startID = 0;
}

InMemoryTablePtr InMemoryTable::Clone() const 
{
    LOG_ERROR("No supported low-overhead clone");
}

void InMemoryTable::SetStartID(Columns::RowID startID)
{
    this->startID = startID;
}

Columns::RowID InMemoryTable::GetStartID() const
{
    return startID;
}

Columns::TuplePtr InMemoryTable::GetTupleCopy(Columns::RowID rid) const
{
    return tuples[startID.Offset(rid)]->Clone();
}

Columns::FieldPtr InMemoryTable::GetFieldCopy(Columns::RowID rid, Columns::ColID cid) const
{
    return tuples[startID.Offset(rid)]->GetFieldCopy(cid.GetID(), nullptr);
}

Columns::Tuples& InMemoryTable::GetTuples()
{
    return tuples;
}

void InMemoryTable::InsertRowTuple(TuplePtr tuple)
{
    tuples.push_back(move(tuple));
}

}