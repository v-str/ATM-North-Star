find_package (Qt5Widgets REQUIRED)
find_package (Qt5Gui)
find_package (Qt5Core)

header_directories (ALL_APPLICATION_HEADERS)
include_directories ("${ALL_APPLICATION_HEADERS}")

file (GLOB_RECURSE HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
file (GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_executable (atm_north_star "${HEADERS}" "${SOURCES}")
target_link_libraries (atm_north_star lib_atm_model lib_cli lib_gui)

add_test (${PROJECT_NAME} ${PROJECT_NAME})
