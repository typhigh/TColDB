#pragma once
#include "../Common/ID.h"

namespace Columns {

class ColID : public Common::ID
{

public:
    ColID() : ID() {}
    ColID(uint64_t id) : ID(id) {}
    ~ColID() {}

    ColID NextColID() {
        return ColID(GetID()+1);
    }
};


}