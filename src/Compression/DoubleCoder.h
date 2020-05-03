#pragma once
#include "defs.h"

namespace Compression {

class DoubleCoder
{
public:
    /// We code float by this way:
    /// (1) -1~125 we just use a bit
    /// (2) ow. positive use 4 bits and negative use 5 bits
    static Storages::Slice EncodeVarFloat(Storages::Slice output, float data);

    static Storages::Slice EncodeVarDouble(Storages::Slice output, double data);

/// Decoder
public:
    static Storages::Slice DecodeVarFloat(Storages::Slice input, float& data);

    static Storages::Slice DecodeVarDouble(Storages::Slice output, double& data);

private:
    union FloatInt
    {
        float   fVal;
        int32_t iVal;
        uint32_t uVal;
    };

};
}