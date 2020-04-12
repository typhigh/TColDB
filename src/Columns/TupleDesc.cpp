#include "TupleDesc.h"
#include "../Utils/VectorUtils.h"
#include "../Utils/StringUtils.h"
using namespace std;
namespace Columns {

TupleDescPtr TupleDesc::Clone() const
{
    TupleDescPtr tuple = make_shared<TupleDesc>(*this);
    return tuple;
}

string TupleDesc::ToString(const string& prefix) const 
{
    string ret = prefix + tableName + "\n";
    for (const ColumnDesc& desc : descs) {
        ret += desc.ToString(prefix);
    }
    return ret;
}

void TupleDesc::SetAlis(const Plan::RenameTable& rename)
{
    for (ColumnDesc& colDesc: descs) {
        colDesc.SetAlis(rename);
    }
}

string TupleDesc::GetFieldName(size_t fieldNo) const 
{
    return descs[fieldNo].GetFieldName();
}

ColumnDescs TupleDesc::GetColumnDescs() const 
{
    return descs;
}

void TupleDesc::MergeOnJoin(TupleDescPtr other)
{
    tableName = "";
    Utils::MergeVectors(this->descs, other->descs);
}

bool TupleDesc::GetFieldNo(const string& fieldName, int& fieldNo) const 
{   
    string name = fieldName;
    for (size_t i = 0; i < descs.size(); ++i) {
        if (Utils::EqualFieldName(fieldName, descs[i].GetFieldName())) {
            fieldNo = i;
            return true;
        }
    }
    return false;
}

string TupleDesc::GetTableName() const 
{
    return tableName;
}

void TupleDesc::SetAlis(const string& alis) 
{
    for (ColumnDesc& colDesc: descs) {
        colDesc.SetAlis(alis);
    }
}

void TupleDesc::MaskByFieldNames(const Plan::FieldNames& fieldNames)
{
    ColumnDescs newDescs;
    for (size_t i = 0; i < descs.size(); ++i) {
        bool contained = false;
        for (const string& fieldName : fieldNames) {
            if (Utils::EqualFieldName(descs[i].GetFieldName(), fieldName)) {
                contained = true;
                break;
            }
        }

        if (contained) {
            newDescs.push_back(descs[i]);           
        }
    }
    descs = newDescs;
}

vector<int> TupleDesc::GetFieldsNoByFrom(TupleDescPtr from) const 
{
    bool missed = false;
    vector<int> ret(descs.size(), -1);
    for (size_t i = 0; i < descs.size(); ++i) {
        for (size_t j = 0; j < from->descs.size(); ++i) {
            if (Utils::EqualFieldName(descs[i].GetFieldName(), from->descs[j].GetFieldName())) {
                ret[i] = j;
                break;
            }
        }
    }
    for (size_t i = 0; i < ret.size(); ++i) {
        if (ret[i] < 0) {
            missed = true;
        }
    }

    if (missed) {
        LOG_WARN("From and To tuple desc are not matched\n To information: %s\n From information %s\n"
            , ToString("").c_str()
            , from->ToString("").c_str()
        );
    }

    return ret;
}

}
