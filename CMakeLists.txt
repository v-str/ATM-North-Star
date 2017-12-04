cmake_minimum_required (VERSION 3.0)

set (PROJECT_NAME atm_north_star)
project (${PROJECT_NAME})

set (CMAKE_INCLUDE_CURRENT_DIR ON)
set (CMAKE_CXX_STANDARD 11)
set (CMAKE_AUTOMOC ON)

find_package (Qt5Widgets REQUIRED)
find_package (Qt5Gui)
find_package (Qt5Core)

include ("${CMAKE_CURRENT_SOURCE_DIR}/cmake_scripts/ccache.cmake")
include ("${CMAKE_CURRENT_SOURCE_DIR}/cmake_scripts/recursive_dirs_macro.cmake")

set (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})

add_subdirectory (lib_atm_model)
add_subdirectory (lib_cli)
add_subdirectory (lib_gui)

header_directories (ALL_APPLICATION_HEADERS)
include_directories ("${ALL_APPLICATION_HEADERS}")

file (GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
file (GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable (atm_north_star "${HEADERS}" "${SOURCES}")
target_link_libraries (atm_north_star lib_atm_model lib_cli lib_gui)

