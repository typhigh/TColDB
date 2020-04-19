#pragma once
#include "Tuple.h"

namespace Columns {
class TupleCreator
{
public:
    static TuplePtr CreateTuple(TupleDescPtr desc);
};


}