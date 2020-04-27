set(HEADERS
	${HEADERS}
    PARENT_SCOPE
)

set (SOURCE
	${SOURCE}
    ${CMAKE_CURRENT_SOURCE_DIR}/BufferPool.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ColumnBlock.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ColumnBlockMeta.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/IndexReader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/InMemoryTable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/OnDiskTable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/TableReader.cpp
    PARENT_SCOPE
)