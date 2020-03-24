#pragma once
#include "TupleDesc.h"
#include <memory>

namespace Columns {

class TableMeta
{
private:
    /* data */
    std::string tabelName; 
public:
    TableMeta(/* args */) {}
    ~TableMeta() {}
    TupleDescPtr GetTupleDesc() const;
    std::string GetTableName() const;
};

using TableMetaPtr = std::shared_ptr<TableMeta>;
}