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
    std::string inputPath;
    std::string outputPath;
    ServerPtr server;

public:
    Client();
    ~Client();

    void SetInput(const std::string& path);
    void SetOutput(const std::string& path);
    void SetServer(ServerPtr server);

    void Start();
    void Query(const std::string& text);

};

using ClientPtr = std::shared_ptr<Client>;
}