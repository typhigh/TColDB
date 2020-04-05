#pragma once
#include "defs.h"
#include "Tuple.h"
#include "TupleDesc.h"
#include "RowID.h"
#include "ColID.h"
#include "TableID.h"
#include "Field/Field.h"
#include "../Executor/Operators/Predicator.h"
#include <memory>

namespace Columns {

class TableMeta
{
private:
    /// data with state
    std::string tabelName; 
    TableID tableID;

//   TablePartMetaPtr tablePartMeta;
//    IndexPartMetaPtr IndexPartMeta;
    
    TupleDescPtr tupleDesc;
    
    /// Check(constraint) condition
    Executor::PredicatorPtr checker;

    /// Default field value
    std::vector<FieldPtr> defaultFields;    

public:
    TableMeta(/* args */) {}
    ~TableMeta() {}
    
    /// Get the table tuple desc copy
    TupleDescPtr GetTupleDescCopy() const;

    /// Set the table tuple desc
    void SetTupleDesc(TupleDescPtr desc);

    /// Get the table name
    std::string GetTableName() const;
    
    /// Get field
    FieldPtr GetField(RowID rid, ColID cid) const;
    
    /// Get tuple count
    size_t GetTupleCount() const;

    void SetChecker(Parser::ExprNodeList* )
    bool CheckCondition(TuplePtr tuple) const;
    
public:
    TableMetaReadOnlyPtr CloneReadOnly() const;
    TableMetaWritePtr CloneWrite() const;
};

}