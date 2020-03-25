#pragma once
#include "TupleDesc.h"
#include "Field/Field.h"
#include <memory>
#include <vector>

namespace Columns {

class Tuple
{

private:
    /* data */
    TupleDescPtr desc;
    std::vector<FieldPtr> fields;
public:
    Tuple(/* args */) {}
    ~Tuple() {}
};

using TuplePtr = std::shared_ptr<Tuple>;

}