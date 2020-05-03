#pragma once
#include "defs.h"
#include "../Common/ID.h"

namespace Storages {

class ColumnBlockID : public Common::ID
{    
public:
    ColumnBlockID() : ID() {}
    ColumnBlockID(uint64_t id) : ID(id) {}
    ~ColumnBlockID() {}

    ColumnBlockID NextColumnBlockID() {
        return ColumnBlockID(GetID()+1);
    }
};

}