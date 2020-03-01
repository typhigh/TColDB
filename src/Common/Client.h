#pragma once

#include "Common.h"
#include <vector>

namespace Common {

class Client
{
private:
    /* data */
    uint64_t clientID;

public:
    Client();
    Client(uint64_t clientID);
    ~Client();
    void Start(std::vector<std::string> commands);
};


using ClientPtr = std::shared_ptr<Client>;
}