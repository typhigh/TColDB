#include "Server.h"
#include "../Databases/Database.h"
#include <thread>

using namespace std;
namespace Common {

Server::Server() 
{
    started.store(false);
    executor = Executor::Executor::GetInstance();
}

Server::~Server()
{
    
}

bool Server::IsStarted() const 
{
    return started.load();
}

void Server::Start() 
{
    if (IsStarted()) {
        return ;
    }

    thread start(StartImpl);
    start.join();
}

void Server::AddClient(ClientID clientID)
{   
    executor->AddClient(clientID);
}

void Server::StartImpl() 
{
    /// We should load meta info 
    Databases::DatabasePtr db = Databases::Database::GetInstance();
    
}

void Server::Produce(CommandPtr cmd) 
{
    commandQueue.Push(cmd);
}

void Server::Consume(CommandPtr& cmd) 
{
    commandQueue.WaitAndPop(cmd);
}

void Server::Query(CommandPtr cmd) 
{
    if (!started.load()) {
        LOG_WARN("Server has not started");
        return ;
    }

    Produce(cmd);

}

}