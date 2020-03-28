#pragma once
#include "RowID.h"
#include "TupleDesc.h"
#include "Field/Field.h"
#include <memory>
#include <vector>

namespace Columns {

class Tuple
{

private:
    /* data */
    RowID rid;
    TupleDescPtr desc;
    std::vector<FieldPtr> fields;
    FieldPtr GetFieldCopyImpl(const std::string& fieldName, int& fieldNo) const;

public:
    Tuple(/* args */) {}
    ~Tuple() {}
    
    /// Use fieldNo to fetch field copy
    /// If not exists, then return nullptr
    FieldPtr GetFieldCopy(int fieldNo) const;

    /// Use fieldName to fetch field copy and the fieldNo
    /// If not exists, then return nullptr 
    FieldPtr GetFieldCopy(const std::string& fieldName, int& fieldNo) const;

};

using TuplePtr = std::shared_ptr<Tuple>;

}