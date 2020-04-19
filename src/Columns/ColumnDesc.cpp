#include "ColumnDesc.h"
#include "../Utils/StringUtils.h"

using namespace std;

namespace Columns {

ColumnDesc::ColumnDesc(const string& fieldName, Parser::FieldType_t fieldType, TableID tableID, ColID cid) 
    : fieldName(fieldName)
    , fieldType(fieldType)
    , tableID(tableID)
    , cid(cid)
{
}

string ColumnDesc::ToString(const string& prefix) const 
{
    string ret = prefix + fieldName + " " + Parser::ToString(fieldType) + " " + to_string(cid.GetID()) + "\n";
    return ret; 
}

void ColumnDesc::SetAlis(string alis, bool isTableAlis) 
{
    if (!isTableAlis) {
        // Rename column name : select person as x from xxx;
        fieldName = alis;
        return;
    } 

    // Rename table name : select * from xxx as x;
    fieldName = alis + "." + Utils::GetPointAfter(fieldName);
}

void ColumnDesc::SetAlis(const Plan::RenameTable& rename)
{   
    rename.FindAlis(fieldName, fieldName);
}

void ColumnDesc::SetPrimary()
{
    primary = true;
}

void ColumnDesc::SetUnique() 
{
    unique = true;
}

string ColumnDesc::GetFieldName() const 
{
    return fieldName;
}

ColID ColumnDesc::GetColID() const
{
    return cid;
}

void ColumnDesc::FillFieldName(const string& tableName)
{
    string pureFieldName = Utils::GetPointAfter(fieldName);
    
    /// It's "xxx.yyy" format yet, do nothing
    if (pureFieldName != fieldName) {
        return ;
    }   

    if (tableName == "") {
        LOG_ERROR("Unexpected empty tableName");
        return;
    }

    fieldName = tableName + "." + pureFieldName;
}

}