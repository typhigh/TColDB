add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/CityHash101)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/BoolArray)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/CRoaring)

set(HEADERS
	${HEADERS}
    PARENT_SCOPE
)

set (SOURCE
	${SOURCE}
    PARENT_SCOPE
)