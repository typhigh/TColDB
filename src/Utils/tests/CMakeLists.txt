find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(BloomFilterUnitTest BloomFilterUnitTest.cpp)

target_link_libraries(
        BloomFilterUnitTest
        ${GTEST_BOTH_LIBRARIES}
        pthread 
        ${CMAKE_PROJECT_NAME}_lib
        )

add_executable(LRUCacheUnitTest LRUCacheUnitTest.cpp)

target_link_libraries(
        LRUCacheUnitTest
        ${GTEST_BOTH_LIBRARIES}
        pthread 
        ${CMAKE_PROJECT_NAME}_lib
        )

gtest_discover_tests(
        BloomFilterUnitTest 
        LRUCacheUnitTest
        )
        
enable_testing()
