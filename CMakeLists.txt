CMAKE_MINIMUM_REQUIRED(VERSION 2.8)  # feel free to try lower
PROJECT(topologist)

ADD_EXECUTABLE(topologist
    src/main.c
    config.c)

ADD_SUBDIRECTORY(quire)
GET_TARGET_PROPERTY(QUIRE_GEN quire-gen LOCATION)
ADD_CUSTOM_COMMAND(
    OUTPUT config.h config.c
    COMMAND ${QUIRE_GEN}
        --source ${CMAKE_CURRENT_SOURCE_DIR}/src/config.yaml
        --c-header config.h
        --c-source config.c
    DEPENDS src/config.yaml quire-gen
    )
SET_SOURCE_FILES_PROPERTIES(
    config.h config.c
    PROPERTIES GENERATED 1
    )
SET_SOURCE_FILES_PROPERTIES(
    src/main.c
    COMPILE_FLAGS "-I${CMAKE_CURRENT_BINARY_DIR}")
TARGET_LINK_LIBRARIES(topologist quire)
INCLUDE_DIRECTORIES(BEFORE SYSTEM quire/include)
