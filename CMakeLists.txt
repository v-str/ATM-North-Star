cmake_minimum_required (VERSION 3.0)

set (CMAKE_CXX_STANDARD 11)

set (PROJECT_NAME AtmNorthStar)
project (${PROJECT_NAME})

set (CMAKE_AUTOMOC ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON)

find_package (Qt5Widgets REQUIRED)
find_package (Qt5Gui)
find_package (Qt5Core)

include ("${CMAKE_CURRENT_SOURCE_DIR}/cmake_scripts/ccache.cmake")
include ("${CMAKE_CURRENT_SOURCE_DIR}/cmake_scripts/recursive_dirs_macro.cmake")

set (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})

add_subdirectory (lib_atm_model)
add_subdirectory (lib_cli)
add_subdirectory (lib_gui)

file (GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable (${PROJECT_NAME} ${SOURCES})
target_link_libraries (${PROJECT_NAME} lib_atm_model lib_cli lib_gui)

header_directories (ALL_ATM_DIRECTORIES)
target_include_directories (${PROJECT_NAME} PUBLIC "${ALL_ATM_DIRECTORIES}")
