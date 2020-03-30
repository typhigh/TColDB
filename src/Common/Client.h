#pragma once

#include "defs.h"
#include "Server.h"
#include <vector>
#include <atomic>

namespace Common {

class Client
{
private:
    /* data */
    ClientID clientID;
    static std::atomic<ClientID> currentID;
    char *input;
    char *output;
    ServerPtr server;

public:
    Client();
    ~Client();

    void SetInput(char* path);
    void SetOutput(char* path);
    void SetServer(ServerPtr server);

    void Start();
    void Query(const std::string& text);

};

using ClientPtr = std::shared_ptr<Client>;
}