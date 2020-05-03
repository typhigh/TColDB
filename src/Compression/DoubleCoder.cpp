#include "DoubleCoder.h"
#include "../Storages/Serialization.h"
#include "../Storages/DeSerialization.h"
using namespace std;
using namespace Storages;

namespace Compression {

Slice DoubleCoder::EncodeVarFloat(Slice output, float data)
{
    assert(output.GetRemain() >= 5);
    FloatInt value;
    value.fVal = data;
    int32_t floatBits = value.iVal;
    constexpr int32_t NEGATIVE_ZERO = 0x80000000;

    /// Refer to lucene's "WriteZFloat"
    int intData = data;
    if (intData == data 
    && intData >= -1
    && intData <= 125
    && floatBits != NEGATIVE_ZERO) {
        /// [-1, 125] 's integer (except -0f)  (1)
        return Serialization::WriteByte(output, 0x80|(intData+1));
    } else if (floatBits >> 31) {
        /// other negative float (2)
        output = Serialization::WriteByte(output, 0xff);
        return Serialization::WriteUint32(output, floatBits);
    } else {
        /// other positive float (3)
        return Serialization::WriteUint32(output, floatBits);
    }
}

Slice DoubleCoder::EncodeVarDouble(Slice output, double data)
{
    LOG_ERROR("Not support double encode");
}

Slice DoubleCoder::DecodeVarFloat(Slice input, float& data)
{
    assert(input.GetRemain() >= 5);
    uint8_t firstByte;
    
    FloatInt value;
    
    input = DeSerialization::ReadByte(input, firstByte);
    if (firstByte == 0xff) {
        /// other negative float (2)
        input = DeSerialization::ReadUint32(input, value.uVal);
        data = value.fVal;
    } else if (firstByte & 0x80) {
        /// [-1, 125] 's integer (except -0f)  (1)
        int intData = (int)(firstByte & 0x7f) - 1;
        data = intData;
    } else {
        /// other positive float (3)
        input = input.Back(1);
        input = DeSerialization::ReadUint32(input, value.uVal);
        data = value.fVal; 
    }
    return input;
}

Slice DoubleCoder::DecodeVarDouble(Slice input, double& data)
{
    LOG_ERROR("Not support double encode");
}

}