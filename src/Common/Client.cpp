#include "Client.h"
#include "Server.h"
#include "Command.h"
#include "../Utils/StringUtils.h"
#include "../Utils/GetSQLFromFile.h"
#include <iostream>
#include <fstream>
#include <thread>

using namespace std;

namespace Common {

atomic<ClientID> Client::currentID = 0;

Client::Client() 
{
    clientID = currentID.load();
    currentID++;
}

Client::~Client() 
{

}

void Client::SetInput(const string& path) 
{
    LOG_INFO("input path change from %s to %s", inputPath.c_str(), path.c_str());
    inputPath = path;
}

void Client::SetOutput(const string& path)
{
    LOG_INFO("output path change from %s to %s", inputPath.c_str(), path.c_str());
    outputPath = path;
}

void Client::SetServer(ServerPtr server)
{
    this->server = server;   
    server->AddClient(clientID);
}

void Client::Start() 
{
    string text = Utils::GetSQLFromFile(inputPath);
    LOG_INFO("Client %lu use text: %s", clientID, text.c_str());
    thread start(
        [this, text] {
            Query(text);
        }
    );
    start.detach();
}

void Client::Query(const string& text) 
{
    while (!server->IsStarted());
    vector<string> commands = Utils::Splite(text, ';');
    cout << commands.size() << endl;
    for (auto& content : commands) {
        content = Utils::NormalizeCommand(content);
        CommandPtr cmd = make_shared<Command>(content, clientID);
        server->Query(cmd);
        string result = cmd->GetResult();
        if (!outputPath.empty()) {
            
        } else {
            cout << result << endl;
        }
        if (result == "Exit") return;
        int k = rand() % 1000;
        this_thread::sleep_for(chrono::microseconds(k));
    }
    LOG_INFO("Client %lu end", clientID);
}

}