set(CMAKE_BUILD_TYPE Debug)

find_package(GTest REQUIRED)
find_package(Snappy)

include_directories(${GTEST_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 17)

add_executable(DateCoderUnitTest DateCoderUnitTest.cpp ../../Parser/SQLParser.cpp)
target_link_libraries(
    DateCoderUnitTest
    sql_parser
    ${GTEST_BOTH_LIBRARIES}
    pthread
    ${CMAKE_PROJECT_NAME}_lib
    snappy
)

add_executable(DoubleCoderUnitTest DoubleCoderUnitTest.cpp ../../Parser/SQLParser.cpp)
target_link_libraries(
    DoubleCoderUnitTest
    sql_parser
    ${GTEST_BOTH_LIBRARIES}
    pthread
    ${CMAKE_PROJECT_NAME}_lib
)

add_executable(IntCoderUnitTest IntCoderUnitTest.cpp ../../Parser/SQLParser.cpp)
target_link_libraries(
    IntCoderUnitTest
    sql_parser
    ${GTEST_BOTH_LIBRARIES}
    pthread
    ${CMAKE_PROJECT_NAME}_lib
)

add_executable(StringCoderUnitTest StringCoderUnitTest.cpp ../../Parser/SQLParser.cpp)
target_link_libraries(
    StringCoderUnitTest
    sql_parser
    ${GTEST_BOTH_LIBRARIES}
    pthread
    ${CMAKE_PROJECT_NAME}_lib
    snappy
)

gtest_discover_tests(
    DateCoderUnitTest
    DoubleCoderUnitTest
    IntCoderUnitTest
    StringCoderUnitTest
)

enable_testing()