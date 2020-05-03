#pragma once
#include "defs.h"
#include "Slice.h"
#include <string>

namespace Storages {

class DeSerialization
{
public:
    static Slice ReadByte(Slice input, uint8_t& byte);

    static Slice ReadUint32(Slice input, uint32_t& data);

    static Slice ReadString(Slice input, size_t length, std::string& data);
};

}