#include <gtest/gtest.h>
#include "../StringCoder.h"
#include "../../Utils/StringUtils.h"
using namespace std;
using namespace Storages;
using namespace Compression;

void TestStringOnce(const std::string& data)
{
    char s[1024];
    Slice slice(s, 1024);
    StringCoder::EnCodeStringWithSnappy(slice, data);
    string y;
    StringCoder::DeCodeStringWithSnappy(slice, y);
    EXPECT_EQ(data, y);
}

TEST(StringCoderUnitTest, testSnappy)
{
    /// Simple
    TestStringOnce("abc");
    TestStringOnce("absdadqdadx ");
    TestStringOnce("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

    /// Some 
    constexpr size_t times = 1;
    for (size_t i = 0; i < times; ++i) {
        string s = Utils::RandomString(10);
        for (size_t j = 0; j < 3; ++j) {
            s += s;
        }
        TestStringOnce(s);
    }
    /*
    /// series string
    char* s = new char[102400];
    Slice slice(s, 102400);
    vector<string> datas(times);
    
    Slice now = slice;
    for (size_t i = 0; i < times; ++i) {
        string s = Utils::RandomString(20);
        datas[i] = s + s + s;
        now = StringCoder::EnCodeStringWithSnappy(now, datas[i]);
    }

    now = slice;
    for (size_t i = 0; i < times; ++i) {
        string s;
        now = StringCoder::DeCodeStringWithSnappy(now, s);
        EXPECT_EQ(s, datas[i]);
    }

    delete s;
    */
}

