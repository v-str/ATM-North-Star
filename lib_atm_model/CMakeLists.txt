cmake_minimum_required (VERSION 3.0)

header_directories (LIB_HEADERS)
include_directories ("${LIB_HEADERS}")

file (GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_library (lib_atm_model STATIC ${SOURCES})
