set(HEADERS
	${HEADERS}
    PARENT_SCOPE
)

set (SOURCE
	${SOURCE}
    ${CMAKE_CURRENT_SOURCE_DIR}/BoolField.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/CharField.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Convertion.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DateField.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/DoubleField.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/FieldsCreator.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/IntField.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/NullField.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/VarcharField.cpp
    PARENT_SCOPE
)