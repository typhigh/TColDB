set(HEADERS
	${HEADERS}
    PARENT_SCOPE
)

set (SOURCE
	${SOURCE}
    ${CMAKE_CURRENT_SOURCE_DIR}/Aggregate.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Aggregator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Filter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Predicator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Project.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Projector.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SeqScan.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Updator.cpp
    PARENT_SCOPE
)