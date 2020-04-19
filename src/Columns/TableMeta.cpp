#include "TableMeta.h"
#include "TupleCreator.h"

#include <sstream>
using namespace std;

namespace Columns {

TableMeta::TableMeta(const string& tableName, TableID tableID, Storages::BufferPoolPtr pool)
    : tableName(tableName)
    , tableID(tableID)
    , onDiskTable(pool)
{
    currentCID = ColID(0);
    currentRID = RowID(0);
}

string TableMeta::ToString() const
{
    stringstream out;
    out << "======== Table Info Begin ========\n"
        << "Table name = " + tableName + "\n"
        << "Column number = " + to_string(tupleDesc->GetColumnDescs().size()) + "\n"
        << tupleDesc->ToString("")
        << checker->ToString("");
    return out.str(); 
}

TupleDescPtr TableMeta::GetTupleDescCopy() const 
{
    return tupleDesc->Clone();
}

void TableMeta::SetTupleDesc(TupleDescPtr desc) 
{
    this->tupleDesc = desc;
}

string TableMeta::GetTableName() const 
{
    return tableName;
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

void TableMeta::SetChecker(Executor::PredicatorPtr checker)
{
    this->checker = checker;
}

bool TableMeta::CheckCondition(TuplePtr tuple) const 
{
    return checker->Predicate(tuple);
}


TableMetaWritePtr TableMeta::CloneWrite() const 
{
    TableMetaWritePtr ret = make_shared<TableMeta>(tableName, tableID);
    ret->currentCID = currentCID;
    ret->currentRID = currentRID;
    ret->inMemoryTable = inMemoryTable;
    ret->onDiskTable = onDiskTable;
    ret->rowBitest = rowBitest;

    for (size_t i = 0; i < defaultFields.size(); ++i) {
        ret->defaultFields.push_back(defaultFields[i]->Clone());
    }

    if (tupleDesc != nullptr) {
        ret->tupleDesc = tupleDesc->Clone();
    }

    if (checker != nullptr) {
        ret->checker = checker->Clone();
    }
    
    return ret;
}

ColID TableMeta::CreateNextColID()
{
    return currentCID = currentCID.NextColID();
}

bool TableMeta::CheckInRange(RowID rid, ColID cid) const
{
    return cid <= currentCID && CheckInRange(rid);
}

bool TableMeta::CheckInRange(RowID rid) const 
{
    return rowBitest.contains(rid.GetID());
}

bool TableMeta::DeleteRow(RowID rid) 
{
    if (!CheckInRange(rid)) {
        return false;
    }
    rowBitest.remove(rid.GetID());
    return true;
}

bool TableMeta::InsertRow(TuplePtr tuple, string& error)
{
    TuplePtr insertedTuple = TupleCreator::CreateTuple(tupleDesc);
    Fields& fields = insertedTuple->fields;

    /// Init the fields
    size_t num = defaultFields.size();
    for (size_t i = 0; i < num; ++i) {
        fields.push_back(nullptr);
    }

    /// Fill the fields by tuple
    TupleDescPtr desc = tuple->GetTupleDesc();
    for (size_t i = 0; i < tuple->fields.size(); ++i) {
        FieldPtr field = move(tuple->fields[i]);
        fields[desc->GetColID(i).GetID()] = move(field);
    }

    /// Fill the fields by default value
    for (size_t i = 0; i < num; ++i) {
        if (fields[i] == nullptr) {
            /// This field is not allowed null
            if (defaultFields[i] == nullptr) {
                error = "field" + tupleDesc->GetFieldName(i) + "can't be null";
                return false;
            }

            fields[i] = defaultFields[i]->Clone();
        }
    }

    if (!checker->Predicate(insertedTuple)) {
        error = "tuple is not satisfied with checker";
        return false;
    }

    InsertRowImpl(tuple);
    return true;
}

void TableMeta::InsertRowImpl(TuplePtr tuple)
{
    
}

}