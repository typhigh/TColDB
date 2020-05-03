#pragma once
#include <cstdint>
#include <cassert>
#include <unordered_map>
#include <string>

namespace Common {

class ID
{
private:
    uint64_t id;

public:
    ID() {}
    ID(uint64_t id) : id(id) {}
    virtual ~ID() {}

    std::string ToString() 
    {
        return std::to_string(id);
    }
    
    uint64_t GetID() const 
    {
        return id;
    }

    bool operator < (const ID& rhs) const 
    {
        return id < rhs.id;
    }
    
    bool operator <= (const ID& rhs) const 
    {
        return id <= rhs.id;
    }

    bool operator == (const ID& rhs) const
    {
        return id == rhs.id;
    }

    size_t Offset(const ID& rhs) const
    {
        assert(rhs.id > id);
        return rhs.id - id;
    }
};

struct IDHashFunc
{
    size_t operator () (const ID& id) const
    {
        return std::hash<uint64_t>() (id.GetID());
    }
};

}