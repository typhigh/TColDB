set(HEADERS
	${HEADERS}
    PARENT_SCOPE
)

set (SOURCE
	${SOURCE}
    ${CMAKE_CURRENT_SOURCE_DIR}/Aggregator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ExecutorContext.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Predicator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Projector.cpp
    PARENT_SCOPE
)