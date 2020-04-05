#pragma once
#include <cstdint>
namespace Columns {

class ColID
{
private:
    uint64_t id;

public:
    ColID(/* args */) {}
    ~ColID() {}
    uint64_t GetID() const {
        return id;
    }

    bool operator < (const ColID& other) const {
        return id < other.id;
    }
};


}