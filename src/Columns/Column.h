#include "ColumnDesc.h"
#include <memory>

namespace Columns {

class Column
{
private:
    /* data */
public:
    Column(/* args */);
    ~Column();
};

using ColumnPtr = std::shared_ptr<Column>;

Column::Column(/* args */)
{
}

Column::~Column()
{
}

}