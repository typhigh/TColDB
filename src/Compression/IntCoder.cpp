#include "IntCoder.h"

using namespace std;
using namespace Storages;
namespace Compression {

Slice IntCoder::EncodeVarSInt32(Slice output, int32_t data)
{
    uint32_t zag = ((data >> 31) ^ (data << 1));
    return EncodeVarUInt32(output, zag);
}

Slice IntCoder::EncodeVarUInt32(Slice output, uint32_t data)
{
    uint8_t* p = reinterpret_cast<uint8_t*>(output.GetData());
    constexpr uint8_t Flag = 1 << 7;
    for (size_t offset = 0; offset < 5; ++offset) {
        if (data < (1<<7)) {
            p[offset] = data;
            return output.RemovePrefix(offset+1);
        } 
        p[offset] = data | Flag;
        data >>= 7;
    }
    assert(false);
}

Slice IntCoder::DecodeVarSInt32(Slice input, int32_t& data)
{
    uint32_t zag;
    Slice ret = DecodeVarUint32(input, zag);
    data = (-(zag & 1)) ^ (zag >> 1);
    return ret;
}

Slice IntCoder::DecodeVarUint32(Slice input, uint32_t& data)
{
    uint8_t* p = reinterpret_cast<uint8_t*>(input.GetData());
    constexpr uint8_t Flag = 1 << 7;
    data = 0;
    for (size_t offset = 0; offset < 5; ++offset) {
        if (p[offset] < (1<<7)) {
            data |= p[offset] << (offset * 7);
            return input.RemovePrefix(offset+1);
        }
        data |= (p[offset] & (~Flag)) << (offset * 7);
    }
    assert(false);
}

}