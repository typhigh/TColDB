#pragma once
#include <memory>

namespace Columns {

class TableMeta;
using TableMetaReadOnlyPtr = std::shared_ptr<const TableMeta>;
using TableMetaWritePtr = std::shared_ptr<TableMeta>;

class Tuple;
using TuplePtr = std::shared_ptr<Tuple>;
}