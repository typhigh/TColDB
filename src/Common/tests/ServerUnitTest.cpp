#include <gtest/gtest.h>
#include "../Server.h"
#include "../ClientFactory.h"

TEST(ServerUnitTest, testDemo) {
    Common::Server::Start();
    Common::ClientPtr client = Common::ClientFactory::CreateClient(0);

}