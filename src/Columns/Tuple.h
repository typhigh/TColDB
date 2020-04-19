#pragma once
#include "defs.h"
#include "RowID.h"
#include "TupleDesc.h"
#include "Field/Field.h"
#include "../Executor/ExecutorContext.h"
#include <memory>
#include <vector>

namespace Columns {

class Tuple
{
private:
    const TupleDescPtr desc;

public:
    std::vector<FieldPtr> fields;

public:
    Tuple(TupleDescPtr desc) : desc(desc){}
    TupleDescPtr GetTupleDesc() const;
    ~Tuple() {}
    
    TuplePtr Clone() const;
    /// Use fieldNo to fetch field copy
    /// If not exists, then return nullptr
    FieldPtr GetFieldCopy(int fieldNo, Executor::ExecutorContextPtr context);

    /// Use fieldName to fetch field copy and the fieldNo
    /// If not exists, then return nullptr 
    FieldPtr GetFieldCopy(const std::string& fieldName, int& fieldNo, Executor::ExecutorContextPtr context);

};

}