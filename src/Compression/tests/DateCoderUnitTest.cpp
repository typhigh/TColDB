#include <gtest/gtest.h>
#include "../DateCoder.h"
#include "../../Utils/StringUtils.h"

using namespace std;
using namespace Compression;
using namespace Storages;

void TestDateOnce(const string& data, size_t need = 0)
{
    char s[10];
    Slice slice(s, 10);
    DateCoder::EnCodeDate(slice, data);
    string y;
    Slice now = DateCoder::DeCodeDate(slice, y);
    EXPECT_EQ(data, y);
    if (need) {
        EXPECT_EQ(now.GetUsedSize(), need);
    }
}

TEST(DateCoderUnitTest, testDate)
{
    /// Simple 
    TestDateOnce("2000-02-11", 1);
    TestDateOnce("2000-12-31", 2);
    TestDateOnce("9000-11-12");
    TestDateOnce("0110-12-11");

    /// Some random
    constexpr size_t times = 1024;
    for (size_t i = 0; i < times; ++i) {
        TestDateOnce(Utils::RandomDate());
    }

    /// series
    char *s = new char[10240];
    vector<string> datas(times);
    Slice slice(s, 10240);
    Slice now = slice;
    for (size_t i = 0; i < times; ++i) {
        datas[i] = Utils::RandomDate();
        now = DateCoder::EnCodeDate(now, datas[i]);
    }

    now = slice;
    for (size_t i = 0; i < times; ++i) {
        string y;
        now = DateCoder::DeCodeDate(now, y);
        EXPECT_EQ(y, datas[i]);
    }
    delete s;
}