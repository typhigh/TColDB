#include "ASTCreateInfo.h"
#include "../Utils/StringUtils.h"
using namespace std;

namespace Parser {

ASTCreateInfo::~ASTCreateInfo() 
{
    delete name;
    if (fields != nullptr) {
        for (FieldDef* ele : *fields) {
            delete ele;
        }
        delete fields;
    }

    if (constraints != nullptr) {
        for (TableConstraint* ele : *constraints) {
            delete ele;
        }
        delete constraints;
    }
}

string ASTCreateInfo::ToString() const 
{
    return "ASTCreateInfo";
}

bool ASTCreateInfo::IsWriteSQL() const
{
    return true;
}

vector<string> ASTCreateInfo::GetTablesRef() const
{
    return vector<string> {Utils::CopyStringFromCString(name)};
}

void ASTCreateInfo::Execute(Executor::ExecutorContextPtr context) const
{
    /// Create a table 
    string tableName = Utils::CopyStringFromCString(name);
    Columns::TableID tableID = context->GetTableID(tableName);
    if (context->GetTableMeta(tableID) != nullptr) {
        LOG_WARN("some users try to create exisited table %s", tableName.c_str());
        return;
    }
    Columns::TableMetaWritePtr tableMetaNew = make_shared<Columns::TableMeta>();
    Columns::ColumnDescs descs;
    for (size_t i = 0; i < fields->size(); ++i) {
        FieldDef* def = fields->at(i);
        descs.emplace_back(def->name, def->type);
    }
    Columns::TupleDescPtr desc = make_shared<Columns::TupleDesc>(tableName, descs);
    tableMetaNew->SetTupleDesc(desc);
    Executor::PredicatorPtr checker = make_shared<Executor::Predicator>();
    for (size_t i = 0; i < constraints->size(); ++i) {
        TableConstraint* constraint = constraints->at(i);
        if (constraint->type == )
    }
}

}