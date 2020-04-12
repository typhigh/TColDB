#include <gtest/gtest.h>
#include "../Server.h"
#include "../Client.h"
using namespace std;
using namespace Common;

void TestFile(const string& path)
{
    Common::ServerPtr server = make_shared<Server>();
    Common::ClientPtr client = make_shared<Client>();
    client->SetServer(server);
    string dataPath = string(getenv("TestData")) + "/" + path;
    client->SetInput(dataPath);
    client->Start();
    server->Start(); 
}

TEST(ServerUnitTest, testCreateAndShow) 
{
//    TestFile("CreateAndShow.sql");
}

TEST(ServerUnitTest, testCreateAndDrop) 
{
//    TestFile("CreateAndDrop.sql");
}

TEST(ServerUnitTest, testSelect) 
{
//    TestFile("Select.sql");
}

TEST(ServerUnitTest, testJoin)
{
    TestFile("Join.sql");
}