#pragma once
#include "defs.h"
#include "../Columns/TableMeta.h"
namespace Plan {

class PlanContext
{
private:
    /* data */
    std::vector<Columns::TableMetaReadOnlyPtr> tableMetasRef;

public:
    PlanContext(/* args */) {}
    ~PlanContext() {}
    
    PlanContext(const std::vector<std::string>& tableNames, bool ReadOnly);
    Columns::TableMetaReadOnlyPtr GetTableMeta(const std::string& tableName) const;
    Columns::TableMetaReadOnlyPtr GetTableMeta() const;
};
using PlanContextPtr = std::shared_ptr<PlanContext>;

}