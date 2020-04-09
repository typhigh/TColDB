#include "ASTCreateInfo.h"
#include "../Utils/StringUtils.h"
#include "../Columns/Field/FieldsCreator.h"
#include "Expression/Expression.h"

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
    /// TODO: Check unique and primary key constraint
    /// Create a table 
    string tableName = Utils::CopyStringFromCString(name);
    Columns::TableID tableID = context->GetTableID(tableName);
    if (context->GetTableMeta(tableID) != nullptr) {
        LOG_WARN("some users try to create exisited table %s", tableName.c_str());
        return;
    }

    Columns::TableMetaWritePtr tableMetaNew = make_shared<Columns::TableMeta>(tableName, tableID);
    Columns::ColumnDescs descs;
    vector<Columns::FieldPtr> defaultFields;

    size_t n = (fields != nullptr ? fields->size() : 0);
    defaultFields.resize(n);

    /// Set tuple desc and default value
    for (size_t i = 0; i < n; ++i) {
        FieldDef* def = fields->at(i);
        descs.emplace_back(def->name, def->type, tableID, tableMetaNew->CreateNextColID());
        if (def->default_value != nullptr) {
            defaultFields[i] = Expression::Eval(def->default_value, nullptr);
        } else if (def->flags & FIELD_FLAG_NOTNULL) {
            /// Don't allow null 
            defaultFields[i] = nullptr;
        } else {
            defaultFields[i] = Columns::FieldsCreator::CreateNullField();
        }
    }
    Columns::TupleDescPtr desc = make_shared<Columns::TupleDesc>(tableName, descs);
    tableMetaNew->SetTupleDesc(desc);
    
    /// Set table constraint checker
    Executor::PredicatorPtr checker = make_shared<Executor::Predicator>();
    n = constraints != nullptr ? constraints->size() : 0;

    for (size_t i = 0; i < n; ++i) {
        TableConstraint* constraint = constraints->at(i);
        table_constraint_type_t type = constraint->type;
        switch (type)
        {
        case TABLE_CONSTRAINT_CHECK:
        {
            checker->Add(constraint->check_cond);
            break;
        }
        case TABLE_CONSTRAINT_PRIMARY_KEY:
        case TABLE_CONSTRAINT_UNIQUE:
        {
            /*TODO*/
            break;
        }
        default:
            LOG_ERROR("unsupported table constraint %s \n", Parser::ToString(type).c_str());
            break;
        }
    }

    tableMetaNew->SetChecker(checker);
    context->SubmitTableMeta(tableID, tableMetaNew);
    context->SubmitResult("done");
}

}