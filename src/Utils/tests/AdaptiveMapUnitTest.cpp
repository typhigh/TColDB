#include <gtest/gtest.h>
#include "../AdaptiveMap.h"
using namespace std;
using namespace Utils;

TEST(AdaptiveMapUnitTest, testSimple)
{
    AdaptiveMap<int, int> self;
    constexpr size_t times = 1024;
    
    for (size_t i = 0; i < times; ++i) {
        self.Insert(i, i);
        int x;
        EXPECT_TRUE(self.Get(i, x));
        EXPECT_EQ(x, i);
    }

    for (size_t i = 0; i < times; ++i) {
        int x;
        EXPECT_TRUE(self.Get(i, x));
        EXPECT_EQ(x, i);
    }
    
    EXPECT_EQ(self.GetSize(), times);
}

TEST(AdaptiveMapUnitTest, testIterator)
{
    AdaptiveMap<int, int> self;
    constexpr size_t times = 1024;
    
    for (size_t i = 0; i < times; ++i) {
        self.Insert(i, -i);
    }

    size_t i = 0;
    for (auto iter = self.Begin(); iter.HasNext(); ++i) {
        auto pair = iter.Next();
        EXPECT_EQ(pair.second, -i);
    }
}

