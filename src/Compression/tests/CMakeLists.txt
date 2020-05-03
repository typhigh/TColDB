set(CMAKE_BUILD_TYPE Debug)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 17)

add_executable(IntCoderUnitTest IntCoderUnitTest.cpp ../../Parser/SQLParser.cpp)
target_link_libraries(
    IntCoderUnitTest
    sql_parser
    ${GTEST_BOTH_LIBRARIES}
    pthread
    ${CMAKE_PROJECT_NAME}_lib
)

add_executable(DoubleCoderUnitTest DoubleCoderUnitTest.cpp ../../Parser/SQLParser.cpp)
target_link_libraries(
    DoubleCoderUnitTest
    sql_parser
    ${GTEST_BOTH_LIBRARIES}
    pthread
    ${CMAKE_PROJECT_NAME}_lib
)

gtest_discover_tests(
    IntCoderUnitTest
    DoubleCoderUnitTest
)

enable_testing()