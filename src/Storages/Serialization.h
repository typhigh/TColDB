#pragma once
#include "defs.h"
#include "Slice.h"

namespace Storages {

class Serialization
{
public:
    /// Write byte to output
    static Slice WriteByte(Slice output, uint8_t byte);

    /// Write uint32 data to output (without compression)
    static Slice WriteUint32(Slice output, uint32_t data);

    /// Write string data to output
    static Slice WriteString(Slice output, const std::string& data);
};



}