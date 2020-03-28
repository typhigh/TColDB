#pragma once
#include <memory>

namespace Columns {

class TableMeta;
using TableMetaReadOnlyPtr = std::shared_ptr<const TableMeta>;
using TableMetaWritePtr = std::shared_ptr<TableMeta>;

}