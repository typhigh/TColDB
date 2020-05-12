find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(AdaptiveMapUnitTest AdaptiveMapUnitTest.cpp ../../Parser/SQLParser.cpp)
target_link_libraries(
        AdaptiveMapUnitTest
        ${GTEST_BOTH_LIBRARIES}
        sql_parser
        pthread 
        ${CMAKE_PROJECT_NAME}_lib
        )

## BloomFilterUnitTest
add_executable(BloomFilterUnitTest BloomFilterUnitTest.cpp ../../Parser/SQLParser.cpp)
target_link_libraries(
        BloomFilterUnitTest
        ${GTEST_BOTH_LIBRARIES}
        sql_parser
        pthread 
        ${CMAKE_PROJECT_NAME}_lib
        )

## LRUCacheUnitTest
add_executable(LRUCacheUnitTest LRUCacheUnitTest.cpp ../../Parser/SQLParser.cpp)
target_link_libraries(
        LRUCacheUnitTest
        ${GTEST_BOTH_LIBRARIES}
        sql_parser
        pthread 
        ${CMAKE_PROJECT_NAME}_lib
        )

gtest_discover_tests(
        AdaptiveMapUnitTest
        BloomFilterUnitTest 
        LRUCacheUnitTest
        )
        
enable_testing()
