add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Rules)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Histogram)

set(HEADERS
	${HEADERS}
    PARENT_SCOPE
)

set (SOURCE
	${SOURCE}
    ${CMAKE_CURRENT_SOURCE_DIR}/Optimizer.cpp
    PARENT_SCOPE
)