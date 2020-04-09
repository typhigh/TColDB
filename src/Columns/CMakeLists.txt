add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Field)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Operations)
set(HEADERS
	${HEADERS}
    PARENT_SCOPE
)

set (SOURCE
	${SOURCE}
    ${CMAKE_CURRENT_SOURCE_DIR}/ColumnDesc.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Table.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/TableCreator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/TableMeta.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Tuple.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/TupleDesc.cpp
    PARENT_SCOPE
)