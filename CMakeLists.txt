cmake_minimum_required (VERSION 3.0)

set (PROJECT_NAME atm_north_star)
project (${PROJECT_NAME})
enable_testing ()

set (CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_AUTOMOC ON)

include ("${CMAKE_CURRENT_SOURCE_DIR}/cmake_scripts/ccache.cmake")
include ("${CMAKE_CURRENT_SOURCE_DIR}/cmake_scripts/recursive_dirs_macro.cmake")

set (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})

header_directories (ALL_APPLICATION_HEADERS)
include_directories ("${ALL_APPLICATION_HEADERS}")

add_subdirectory (application)
add_subdirectory (lib_atm_model)
add_subdirectory (lib_cli)
add_subdirectory (lib_gui)


