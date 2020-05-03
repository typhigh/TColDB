#include "Serialization.h"
using namespace std;

namespace Storages {

Slice Serialization::WriteByte(Slice output, uint8_t byte)
{
    assert(output.GetRemain() >= 1);
    uint8_t* p = reinterpret_cast<uint8_t*>(output.GetData());
    *p = byte;
    return output.RemovePrefix(1);
}

Slice Serialization::WriteUint32(Slice output, uint32_t data)
{
    assert(output.GetRemain() >= 4);
    uint8_t* p = reinterpret_cast<uint8_t*>(output.GetData());
    constexpr uint8_t BitMask = 0xff;
    p[3] = data & BitMask;
    p[2] = (data >> 8) & BitMask;
    p[1] = (data >> 16) & BitMask;
    p[0] = (data >> 24) & BitMask;
    return output.RemovePrefix(4); 
}

}