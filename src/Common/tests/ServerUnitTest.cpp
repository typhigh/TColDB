#include <gtest/gtest.h>
#include "../Server.h"
#include "../Client.h"
using namespace std;
using namespace Common;

TEST(ServerUnitTest, testDemo) {
    Common::ServerPtr server = make_shared<Server>();
    Common::ClientPtr client = make_shared<Client>();
    client->SetServer(server);
    client->SetInput("testdata1.sql");
    client->Start();
}