#include "Plan.h"
using namespace std;

namespace Plan {

PlanContextPtr Plan::GetPlanContext() const 
{
    return context;
}

void Plan::SetPlanContext(PlanContextPtr context) 
{
    this->context = context;
}

PlanPtr Plan::GetParent() 
{
    return parent;
}

void Plan::SetParent(PlanPtr parent) 
{
    this->parent = parent;
}

FieldNames Plan::GetFieldNames() const 
{
    return fieldNames;
}

void Plan::SetFieldNames(FieldNames fieldNames)
{
    this->fieldNames = fieldNames;
}

Columns::TupleDescPtr Plan::GetTupleDescCopy() const 
{
    return desc->Clone();
}

void Plan::SetTupleDesc(Columns::TupleDescPtr desc)
{
    this->desc = desc;
}

RenameTable Plan::GetRenameTable() const 
{
    return renameTable;
}

void Plan::SetRenameTable(RenameTable renameTable)
{
    this->renameTable = renameTable;
}

void Plan::SetFieldsNo(const vector<int>& fieldsNo) 
{
    this->fieldsNo = fieldsNo;
}

}