#pragma once
#include "defs.h"
#include "../Columns/TableMeta.h"
namespace Plan {

class PlanContext
{
private:
    /* data */
    std::vector<Columns::TableMetaPtr> tableMetasRef;

public:
    PlanContext(/* args */) {}
    ~PlanContext() {}
    
    PlanContext(const std::vector<std::string>& tableNames, bool ReadOnly);
    Columns::TableMetaPtr GetTableMeta(const std::string& tableName) const;
    Columns::TableMetaPtr GetTableMeta() const;
};
using PlanContextPtr = std::shared_ptr<PlanContext>;

}