#include "Slice.h"
using namespace std;

namespace Storages {

char* Slice::GetData() 
{
    return data + pos;
}

size_t Slice::GetSize() const
{
    return pos + remain;
}

size_t Slice::GetRemain() const 
{
    return remain;
}

size_t Slice::GetUsedSize() const 
{
    return pos;
}

Slice& Slice::RemovePrefix(size_t offset)
{
    offset = min(offset, remain);
    remain -= offset;
    pos += offset;
    return *this;
}

Slice& Slice::Back(size_t offset)
{
    offset = min(offset, pos);
    remain += offset;
    pos -= offset;
    return *this;
}

}