add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Operators)
set(HEADERS
	${HEADERS}
    PARENT_SCOPE
)

set (SOURCE
	${SOURCE}
    ${CMAKE_CURRENT_SOURCE_DIR}/Executor.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ExecutorContext.cpp
    PARENT_SCOPE
)