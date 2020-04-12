#include "TableMeta.h"
#include <sstream>
using namespace std;

namespace Columns {

TableMeta::TableMeta(const string& tableName, TableID tableID)
    : tableName(tableName)
    , tableID(tableID)
{
    currentCid = ColID(0);
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
    ret->currentCid = currentCid;

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
    return currentCid = currentCid.NextColID();
}

}