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
    TableMetaPtr GetCurrentMeta() const;
};

using TablePtr = std::shared_ptr<Table>;
}