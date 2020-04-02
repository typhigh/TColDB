#pragma once
#include <cstdint>
namespace Columns {

class RowID
{
private:
    uint64_t id;

public:
    RowID(/* args */) {}
    ~RowID() {}
    uint64_t GetID() const {
        return id;
    }
};

}