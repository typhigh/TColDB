#include <gtest/gtest.h>
#include "../IntCoder.h"

using namespace std;
using namespace Compression;
using namespace Storages;
TEST(IntCoderUnitTest, testVarint32) 
{
    char buff[1024];
    /// Single one value
    Slice slice(buff, 2);
    IntCoder::EncodeVarSInt32(slice, -100);
    int x;
    IntCoder::DecodeVarSInt32(slice, x);
    EXPECT_EQ(x, -100);

    for (int i = -100; i < 100; ++i) {
        IntCoder::EncodeVarSInt32(slice, i);
        int x;
        IntCoder::DecodeVarSInt32(slice, x);
        EXPECT_EQ(x, i);
    }

    /// Series values
    slice = Slice(buff, 1024);
    Slice now = slice;
    for (int i = -10; i < 10; ++i) {
        now = IntCoder::EncodeVarSInt32(now, i);
    }

    EXPECT_EQ(now.GetUsedSize(), 20);
    now = slice;
    for (int i = -10; i < 10; ++i) {
        int x;
        now = IntCoder::DecodeVarSInt32(now, x);
        EXPECT_EQ(x, i);
    }
}