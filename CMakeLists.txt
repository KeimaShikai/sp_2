cmake_minimum_required(VERSION 3.0)
project(sample)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json" )
    EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
        ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
    )
endif()

#include directories
list(APPEND HEADERS "Sources/hdr")

#source files
list(APPEND SOURCES "Sources/hdr/cTime.h")
#list(APPEND SOURCES "Sources/src/cTime.cpp")
list(APPEND SOURCES "Sources/main.cpp")

include_directories(${HEADERS})

add_executable(example ${SOURCES})
