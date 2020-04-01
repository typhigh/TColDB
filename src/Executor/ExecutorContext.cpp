#include "ExecutorContext.h"
#include "../Plan/PlanContext.h"
using namespace std;

namespace Executor {

ExecutorContext::ExecutorContext(const std::vector<Columns::TableMetaReadOnlyPtr>& tableMetas, ExecutorPtr executor)
    : tableMetas(tableMetas)
    , executor(executor)
{
}

Plan::PlanContextPtr ExecutorContext::GetPlanContext()
{
    return make_shared<Plan::PlanContext>(shared_from_this());
}

Columns::FieldPtr ExecutorContext::FetchField(Columns::RowID rid, Columns::ColID cid) const
{
    if (tableMetas.size() != 1) {
        LOG_ERROR("expected only one tableMeta");
        return nullptr;
    }

    Columns::TableMetaReadOnlyPtr tableMeta = tableMetas[0]; 
    return tableMeta->GetField(rid, cid);
}

Columns::FieldPtr ExecutorContext::FetchField(const std::string& tableName, Columns::RowID rid, Columns::ColID cid) const
{
    Columns::TableMetaReadOnlyPtr tableMeta = GetTableMeta(tableName);
    if (tableMeta == nullptr) {
        LOG_ERROR("No such table %s", tableName.c_str());
        return nullptr;
    }
    return tableMeta->GetField(rid, cid);    
}

Columns::TupleDescPtr ExecutorContext::GetTableTupleDesc() const
{
    if (tableMetas.size() != 1) {
        LOG_ERROR("expected only one tableMeta");
        return nullptr;
    }
    Columns::TableMetaReadOnlyPtr tableMeta = tableMetas[0];
    return tableMeta->GetTupleDesc();
}

Columns::TupleDescPtr ExecutorContext::GetTableTupleDesc(const std::string& tableName) const
{
    Columns::TableMetaReadOnlyPtr tableMeta = GetTableMeta(tableName);
    if (tableMeta == nullptr) {
        LOG_ERROR("No such table %s", tableName.c_str());
        return nullptr;
    }
    return tableMeta->GetTupleDesc();
}

Columns::TableMetaReadOnlyPtr ExecutorContext::GetTableMeta(const std::string& tableName) const 
{
    Columns::TableMetaReadOnlyPtr tableMeta;
    for (auto ele: tableMetas) {
        if (ele->GetTableName() == tableName) {
            tableMeta = ele;
            break;
        }
    }
    return tableMeta;
}

}