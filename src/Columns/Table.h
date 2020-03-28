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
    TableMetaReadOnlyPtr GetCurrentReadOnlyTableMeta() const;

    /// The current write table meta is only read, we should create a newer version 
    TableMetaReadOnlyPtr GetCurrentWriteTableMeta() const;
    void SetCurrentReadOnlyTableMeta(TableMetaReadOnlyPtr&& tableMeta);
    void SetCurrentWriteTableMeta(TableMetaReadOnlyPtr&& tableMeta); 
};

using TablePtr = std::shared_ptr<Table>;
}