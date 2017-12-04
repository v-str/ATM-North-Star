cmake_minimum_required (VERSION 3.0)

find_package (Qt5Widgets REQUIRED)
find_package (Qt5Gui)
find_package (Qt5Core)

header_directories (LIB_HEADERS)
include_directories ("${LIB_HEADERS}")

file (GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_subdirectory (external_libraries/font_size_generator)

qt5_add_resources (RESOURCES atm_resources.qrc)

add_library (lib_gui STATIC ${SOURCES} ${FORMS_HEADERS} ${RESOURCES})
target_link_libraries (${lib_gui} lib_font_size_generator)

qt5_use_modules (lib_gui Widgets)
