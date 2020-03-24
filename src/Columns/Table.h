#pragma once
#include "TableMeta.h"
#include "../Utils/MultiVersion.h"
namespace Columns {

class Table
{
private:
    /* data */
    MultiVersion<TableMeta> currentReadOnlyTableMeta;
    MultiVersion<TableMeta> currentWriteTableMeta;

public:
    Table(/* args */) {}
    ~Table() {}
    TableMetaPtr GetCurrentReadOnlyTableMeta() const;
    TableMetaPtr GetCurrentWriteTableMeta() const;
    void SetCurrentReadOnlyTableMeta(TableMetaPtr& tableMeta);
    void SetCurrentWriteTableMeta(TableMetaPtr& tableMeta); 
};

using TablePtr = std::shared_ptr<Table>;
}