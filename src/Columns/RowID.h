#pragma once
#include "../Common/ID.h"

namespace Columns {

class RowID : public Common::ID
{

public:
    RowID() : ID() {}
    RowID(uint64_t id) : ID(id) {}
    ~RowID() {}

    RowID NextRowID() {
        return RowID(GetID()+1);
    }
};


}