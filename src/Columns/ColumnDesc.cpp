#include "ColumnDesc.h"
#include "../Utils/StringUtils.h"

using namespace std;

namespace Columns {

string ColumnDesc::ToString() const 
{
    string ret = this->fieldName + Parser::ToString(this->fieldType) + to_string(this->cid.GetID()) + "\n";
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

string ColumnDesc::GetFieldName() const 
{
    return fieldName;
}

}