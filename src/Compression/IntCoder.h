#pragma once
#include "defs.h"
#include <cstdint>
namespace Compression {

class IntCoder
{
/// Encoder
public:
    /// We use zag format to code sign int32 by uint32
    /// 0->0 -1->1 1->2 -2->3 2->4 ...
    /// Then use EncodeVarUInt32 to do it
    static Storages::Slice EncodeVarSInt32(Storages::Slice output, int32_t data);

    /// We use varint int code
    /// every 7 bits in a byte and a bit is FLAG
    /// 0xxxxxxx 1xxxxxxx 1xxxxxxx to express the int
    static Storages::Slice EncodeVarUInt32(Storages::Slice output, uint32_t data);

/// Decoder
public:
    static Storages::Slice DecodeVarSInt32(Storages::Slice input, int32_t& data);

    static Storages::Slice DecodeVarUint32(Storages::Slice output, uint32_t& data);
};

}