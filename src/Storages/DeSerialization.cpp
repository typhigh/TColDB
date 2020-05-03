#include "DeSerialization.h"
using namespace std;

namespace Storages {

Slice DeSerialization::ReadByte(Slice input, uint8_t& byte)
{
    assert(input.GetRemain() >= 1);
    uint8_t* p = reinterpret_cast<uint8_t*>(input.GetData());
    byte = *p;
    return input.RemovePrefix(1);
}

Slice DeSerialization::ReadUint32(Slice input, uint32_t& data)
{
    assert(input.GetRemain() >= 4);
    uint8_t* p = reinterpret_cast<uint8_t*>(input.GetData());
    data = p[3] | (p[2] << 8) | (p[1] << 16) | (p[0] << 24);
    return input.RemovePrefix(4);
}

Slice DeSerialization::ReadString(Slice input, size_t length, string& data)
{   
    assert(input.GetRemain() >= length);
    char* p = input.GetData();
    data.assign(p, length);
    return input.RemovePrefix(length);
}

}