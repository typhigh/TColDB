#pragma once
#include "defs.h"
#include "../Columns/Tuple.h"
#include "../Columns/RowID.h"
namespace Storages {

class InMemoryTable
{
private:
    Columns::RowID startID;
    std::vector<Columns::TuplePtr> tuples;

public:
    InMemoryTable(/* args */) {}
    ~InMemoryTable() {}
    void Clear();
    
    void SetStartID(Columns::RowID startID);

    Columns::RowID GetStartID() const;

    /// Get tuple copy    
    Columns::TuplePtr GetTupleCopy(Columns::RowID rid) const;

    Columns::Tuples& GetTuples();

    void InsertRowTuple(Columns::TuplePtr tuple);
};


}