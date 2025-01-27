cmake_minimum_required(VERSION 2.6)

project(TColDB)
add_subdirectory(src/Columns)
add_subdirectory(src/Common)
add_subdirectory(src/Concurrency)
add_subdirectory(src/Databases)
add_subdirectory(src/Executor)
add_subdirectory(src/Indexs)
add_subdirectory(src/Optimizer)
add_subdirectory(src/Parser)
add_subdirectory(src/Plan)
add_subdirectory(src/Storages)
add_subdirectory(src/ThreePart)
add_subdirectory(src/Utils)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BINARY_DIR build)
set(EXECUTABLE_OUTPUT_PATH build)

set(HEADERS
	${HEADERS}
)

set (SOURCE
	${SOURCE}
)

enable_testing()

add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCE} ${HEADERS})
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp src/Parser/SQLParser.cpp)
target_link_libraries(
	${CMAKE_PROJECT_NAME} 					
	sql_parser
	pthread
	${CMAKE_PROJECT_NAME}_lib
)

