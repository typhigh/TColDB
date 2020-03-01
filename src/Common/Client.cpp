#include "Client.h"
#include "Server.h"
#include "../Utils/StringUtils.h"

using namespace std;

namespace Common {

Client::Client() {

}

Client::Client(uint64_t clientID) : clientID(clientID) {

}

Client::~Client() {

}

void Start(vector<string> commands) {
    for (string &cmd : commands) {
        Server::AddCommand(Utils::NormalizeCommand(cmd));
    }
}

}