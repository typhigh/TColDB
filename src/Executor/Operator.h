#include "../Common/Common.h"
#include "../Columns/ColumnChunk.h"

namespace Executor {

// The base class for many operator
class Operator
{
public:
    // Open Operator;
    virtual void Open() = 0;

    // Return whether operator has next element
    virtual bool HashNext() = 0;

    // Return next tuple
    virtual Columns::ColumnChunkPtr Next() = 0;

    // Close and ReOpen the operator
    virtual void Rewind() = 0;

    // Close the operator
    virtual void Close() = 0;
};

}