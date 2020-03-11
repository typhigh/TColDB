#include <gtest/gtest.h>
#include <iostream>
#include <cstdlib>
#include "../LRUCache.h"
#include "../ThreadPool.h"

using namespace Utils;
using namespace std;

using SimpleLRUCache = LRUCache<int, int>;

TEST(LRUCacheUnitTest, SingleProcess) 
{
    SimpleLRUCache* cache = new SimpleLRUCache (10);
    for (int i = 0; i < 10; ++i) {
        cache->Insert(i, make_shared<int>(i));
    } 
    EXPECT_FALSE(cache->Get(10));
    EXPECT_TRUE(cache->Get(9));
    cache->Insert(10, make_shared<int>(10));
    EXPECT_FALSE(cache->Get(0));
    EXPECT_TRUE(cache->Get(1));
    cache->Insert(0, make_shared<int>(0));
    EXPECT_FALSE(cache->Get(2));
    delete cache;
} 

void WorkFunc(SimpleLRUCache* cache) 
{
    constexpr int MAX = 100;
    constexpr int TIMES = 1000;
    for (int i = 0; i < TIMES; ++i) {
        int k = rand() % MAX;
        cache->Insert(k, make_shared<int> (k));
        std::this_thread::sleep_for(std::chrono::microseconds(k));
        cache->Get(k);
    }
}

TEST(LRUCacheUnitTest, MultipleProcess)
{
    srand((unsigned) time(NULL));
    SimpleLRUCache* cache = new SimpleLRUCache (10);
    ThreadPool* pool = new ThreadPool("TestPool", 20);
    pool->StartUp();
    for (int i = 0; i < 50; ++i) {
        pool->Submit(WorkFunc, cache);
    }
    pool->ShutDown();
    cout << cache->GetHitRatio() << endl;
    EXPECT_TRUE(cache->GetHitRatio() < 0.5);
}