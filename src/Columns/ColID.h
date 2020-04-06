#pragma once
#include <cstdint>
namespace Columns {

class ColID
{
private:
    uint64_t id;

public:
    ColID() {}
    ColID(uint64_t id) : id(id) {}
    ~ColID() {}
    uint64_t GetID() const {
        return id;
    }

    ColID NextColID() {
        return ColID(id+1);
    }

    bool operator < (const ColID& other) const {
        return id < other.id;
    }
};


}