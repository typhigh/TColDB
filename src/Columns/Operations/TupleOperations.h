#pragma once
#include "../Tuple.h"

namespace Columns {

class TupleOperations
{
public:
    /// Merge tuple descs at join
    /// Example: table1 {"x" "y"} table2 {"x" "k"} => {"table1.x" "table1.y" "table2.x" "table2.k"}
    static TupleDescPtr MergeTupleDescsOnJoin(TupleDescs descs);

};


}