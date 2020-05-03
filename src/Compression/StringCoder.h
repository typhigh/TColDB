#pragma once
#include "defs.h"

namespace Compression {

class StringCoder
{
public:
    /// Encode string with format
    /// Length | snappy-string 
    static Storages::Slice EnCodeStringWithSnappy(Storages::Slice output,const std::string& data);

public:
    static Storages::Slice DeCodeStringWithSnappy(Storages::Slice input, std::string& data);
};

}