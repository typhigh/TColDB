#include "StringCoder.h"
#include "IntCoder.h"
#include "../Storages/Serialization.h"
#include "../Storages/DeSerialization.h"
#include <snappy.h>
using namespace std;
using namespace Storages;

namespace Compression {

Slice StringCoder::EnCodeStringWithSnappy(Slice output, const string& data)
{
    string compress;
    snappy::Compress(data.c_str(), data.size(), &compress);
    size_t length = compress.size();
    assert(output.GetRemain() >= length + 5);
//    LOG_INFO("compress size is %lu", length);
    output = IntCoder::EncodeVarUInt32(output, length);
    output = Serialization::WriteString(output, compress);
    return output;
}

Slice StringCoder::DeCodeStringWithSnappy(Slice input, string& data)
{
    string compress;
    uint32_t length;
    input = IntCoder::DecodeVarUint32(input, length);
    input = DeSerialization::ReadString(input, length, compress);
    snappy::Uncompress(compress.c_str(), compress.size(), &data);
    return input;
}

}