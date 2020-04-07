#include <gtest/gtest.h>
#include "../Server.h"
#include "../Client.h"
using namespace std;
using namespace Common;

TEST(ServerUnitTest, testDemo) {
    Common::ServerPtr server = make_shared<Server>();
    Common::ClientPtr client = make_shared<Client>();
    client->SetServer(server);
    string path = getenv("TestData");
    path += "/CreateAndShow.sql";
    client->SetInput(path);
    client->Start();
    server->Start();
}