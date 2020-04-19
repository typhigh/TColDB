#include "InMemoryTable.h"
using namespace std;
using namespace Columns;

namespace Storage {

void InMemoryTable::Clear()
{
    tuples.clear();
    startID = 0;
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
    return tuples[startID.offset(rid)]->Clone();
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