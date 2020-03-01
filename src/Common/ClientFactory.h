#pragma once
#include "Client.h"

namespace Common {
class ClientFactory
{
public:
    static ClientPtr CreateClient(uint64_t id) {
        return std::make_shared<Client>(id);
    }
};
    
}