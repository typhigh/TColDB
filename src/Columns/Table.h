#pragma once
#include "TableMeta.h"
#include <memory>
namespace Columns {

class Table
{
private:
    /* data */
public:
    Table(/* args */) {}
    ~Table() {}
    TableMetaPtr GetCurrentWriteMeta() const;
    TableMetaPtr GetCurrentReadOnlyMeta() const;
};

using TablePtr = std::shared_ptr<Table>;
}