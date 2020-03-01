#pragma once
#include "Command.h"
#include "../Utils/ProductConsumerQueue.h"

namespace Common {

class Server
{
private:
    /* data */
    static Utils::ProductConsumerQueue<Command> commandQueue;
    
    static void Produce(const Command& cmd);
    static void Consume(Command& cmd);
public:
    static void Start();
    static void AddCommand(const std::string& content);
};


}