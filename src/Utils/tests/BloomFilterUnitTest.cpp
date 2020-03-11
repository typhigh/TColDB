#include <gtest/gtest.h>
#include <iostream>
#include "../BloomFilter.h"
#include "../StringUtils.h"

using namespace std;
using namespace Utils;

TEST(BloomFilterUnitTest, AddAndContain) 
{
    BloomFilter* filter = new BloomFilter(1000, 10);
    vector<string> datas;
    const int NUMS = 25;
    for (int i = 0; i < NUMS; ++i) {
        datas.push_back(RandomString(i+10));
        filter->Add(datas[i].c_str(), datas[i].size());
    }
    for (int i = 0; i < NUMS; ++i) {
        EXPECT_TRUE(filter->Contain(datas[i].c_str(), datas[i].size()));
    }
    EXPECT_FALSE(filter->Contain(datas[2].c_str(), 3));
    filter->Clear();
    for (int i = 0; i < NUMS; ++i) {
        EXPECT_FALSE(filter->Contain(datas[i].c_str(), datas[i].size()));
    }
    delete filter;
}
