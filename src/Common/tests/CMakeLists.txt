find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 17)

add_executable(ServerUnitTest ServerUnitTest.cpp ../../Parser/SQLParser.cpp)

target_link_libraries(ServerUnitTest
        ${GTEST_BOTH_LIBRARIES}
        pthread 
        sql_parser
        ${CMAKE_PROJECT_NAME}_lib
        )

gtest_discover_tests(ServerUnitTest)
enable_testing()