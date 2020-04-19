#pragma once
#include <memory>
#include <functional>

namespace Columns {

class TableMeta;
using TableMetaReadOnlyPtr = std::shared_ptr<const TableMeta>;
using TableMetaWritePtr = std::shared_ptr<TableMeta>;

class Tuple;
using TuplePtr = std::shared_ptr<Tuple>;
using Tuples = std::vector<TuplePtr>;

class Field;
using FieldDeleteFunc = std::function<void (Field*)>;
using FieldPtr = std::unique_ptr<Field, FieldDeleteFunc>;
using Fields = std::vector<FieldPtr>;

}