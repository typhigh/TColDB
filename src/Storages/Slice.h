#pragma once
#include "defs.h"

namespace Storages {

/// Write slice
class Slice
{
private:
    char* data = nullptr;
    size_t pos = 0;
    size_t remain = 0;

public:
    Slice() {}
    ~Slice() {}
    Slice(char* data, size_t n) : data(data), pos(0), remain(n) {}
    Slice(char* data, size_t pos, size_t remain) : data(data), pos(pos), remain(remain) {}
    Slice(const Slice&) = default;

public:
    char* GetData();
    size_t GetSize() const;
    size_t GetRemain() const;
    size_t GetUsedSize() const;

    Slice& RemovePrefix(size_t offset);
    Slice& Back(size_t offset);
};


}