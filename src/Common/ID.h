#pragma once
#include <cstdint>
namespace Common {

class ID
{
private:
    uint64_t id;

public:
    ID() {}
    ID(uint64_t id) : id(id) {}
    virtual ~ID() {}
    uint64_t GetID() const {
        return id;
    }

    bool operator < (const ID& other) const {
        return id < other.id;
    }
    
    bool operator <= (const ID& other) const {
        return id <= other.id;
    }
};


}