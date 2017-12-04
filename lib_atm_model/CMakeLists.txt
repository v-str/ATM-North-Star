cmake_minimum_required (VERSION 3.0)

set (CMAKE_BUILD_TYPE Release)

header_directories (ALL_APPLICATION_HEADERS)
include_directories ("${ALL_APPLICATION_HEADERS}")

file (GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library (lib_atm_model STATIC ${SOURCES})
