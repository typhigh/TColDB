
#include <gtest/gtest.h>
#include "../DoubleCoder.h"
using namespace std;
using namespace Compression;
using namespace Storages;

void TestFloatOnce(float x, size_t need = 0)
{
    char data[1024];
    Slice slice(data, 5);
    DoubleCoder::EncodeVarFloat(slice, x);
    float y;
    slice = DoubleCoder::DecodeVarFloat(slice, y);    
    ASSERT_EQ(x, y);
    if (need) {
        ASSERT_EQ(slice.GetUsedSize(), need);
    }
}

TEST(DoubleCoderUnitTest, testFloat)
{   

    TestFloatOnce(-1, 1);
    TestFloatOnce(0, 1);
    TestFloatOnce(1, 1);
    TestFloatOnce(-0.0f, 5);

    /// (1) [-1,125] 's int except -0.0f
    for (int i = -1; i <= 125; ++i) {
        TestFloatOnce(i, 1);
    }

    /// (3) other positive
    constexpr size_t times = 1024;
    for (size_t i = 0; i < times; ++i) {
        float x = 1.0 * rand() / RAND_MAX;
        if (x == 1.0 || x == 0) continue;
        TestFloatOnce(x, 4);
    }

    /// (2) other negative
    for (size_t i = 0; i < times; ++i) {
        float x = 1.0 * rand() / RAND_MAX;
        if (x == 1.0 || x == 0) continue;
        TestFloatOnce(-x, 5);
    }
}