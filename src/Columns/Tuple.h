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
    FieldPtr GetFieldCopy(int fieldNo) const;
    FieldPtr GetFieldCopy(const std::string fieldName) const;
};

using TuplePtr = std::shared_ptr<Tuple>;

}