add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/Operations)
set(HEADERS
	${HEADERS}
    PARENT_SCOPE
)

set (SOURCE
	${SOURCE}
    ${CMAKE_CURRENT_SOURCE_DIR}/AggregatePlan.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DeletePlan.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/FilterPlan.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/JoinPlan.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Plan.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PlanContext.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/PlansCreator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ProjectPlan.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ScanPlan.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/SelectPlan.cpp 
    ${CMAKE_CURRENT_SOURCE_DIR}/UpdatePlan.cpp
    PARENT_SCOPE
)