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

    thread start(
        [this] {
            StartImpl();
        }
    );
    start.join();
}

void Server::AddClient(ClientID clientID)
{   
    executor->AddClient(clientID);
}

void Server::StartImpl() 
{
    LOG_INFO("Server start");
    
    /// We should load meta info
    Databases::DatabasePtr db = Databases::Database::GetInstance(); 
    
    /// Start executor
    executor->StartUp();

    started.store(true); 
    
    /// last is used as address, no other usage
    CommandWrap* last = nullptr;
    while (!executor->IsNoneClients()) {
        CommandWrapPtr cmd;
        Consume(cmd);

        if (cmd == nullptr) {
            /// Maybe come from executor
            continue;
        }

        LOG_INFO("Server get a command \n%s", cmd->ToString().c_str());
        bool tryExecute = executor->TryExecuteStatement(cmd);
        LOG_DEBUG("Yes oh 3 and is %d", tryExecute);
        if (!tryExecute) {
//            LOG_DEBUG("Try fails");
            /// Put back if can't execute
            Produce(cmd);
            if (last == cmd.get()) {
                /// This fail command is the same as last, just sleep
                this_thread::sleep_for(chrono::microseconds(rand() % 1000));
                last = nullptr;
            } else {
                last = cmd.get();
            }
        } 
    }

    /// End 
    LOG_INFO("Server shut down");
    executor->ShutDown();
}

void Server::Produce(CommandWrapPtr cmd) 
{
    executor->Produce(cmd);
}

void Server::Consume(CommandWrapPtr& cmd) 
{
    executor->Consume(cmd);
}

void Server::Query(CommandPtr cmd) 
{
    if (!started.load()) {
        LOG_WARN("Server has not started");
        return ;
    }
    CommandWrapPtr wrap = make_shared<CommandWrap>(cmd);
    Produce(wrap);
}

}