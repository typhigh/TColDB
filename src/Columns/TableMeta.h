#include "TupleDesc.h"
#include <memory>

namespace Columns {

class TableMeta
{
private:
    /* data */

public:
    TableMeta(/* args */);
    ~TableMeta();
    TupleDescPtr GetTupleDesc() const;
};

using TableMetaPtr = std::shared_ptr<TableMeta>;
}