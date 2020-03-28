#pragma once
#include "ColumnDesc.h"
#include <memory>
#include <vector>
namespace Columns {


class TupleDesc
{
private:
    /* data */
    std::vector<ColumnDesc> desc;
    using TupleDescPtr = std::shared_ptr<TupleDesc>;
public:
    TupleDesc(/* args */) {}
    ~TupleDesc() {}
    TupleDescPtr Clone() const;

    void SetAlis(std::string alis);
    std::string GetFieldName(size_t i) const;
};

using TupleDescPtr = std::shared_ptr<TupleDesc>;

}