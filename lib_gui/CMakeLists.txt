cmake_minimum_required (VERSION 3.0)

set (CMAKE_AUTOMOC ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON)

find_package (Qt5Widgets REQUIRED)
find_package (Qt5Gui)
find_package (Qt5Core)

INCLUDE_DIRECTORIES (atm_widgets
		     features/animation
		     features/service
		     images
                     operation_widgets/base
		     operation_widgets/description_menu
		     operation_widgets/initial_menu
		     operation_widgets/login_menu
		     operation_widgets/registration_menu
                     operation_widgets/splash_screen
                     operation_widgets/main_frame
                     operation_widgets/main_widget
		     subwidgets
                     widgets_appearance
                     widgets_arrangement/common/modificators/composite
                     widgets_arrangement/common/modificators/primitive
                     widgets_arrangement/common/widgets_geometries
                     widgets_arrangement/widgets
                     external_libraries/font_size_generator)

file (GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

add_subdirectory (external_libraries/font_size_generator)

qt5_wrap_ui (FORMS_HEADERS ${UI_HEADERS})
qt5_add_resources (RESOURCES atm_resources.qrc)

add_library (lib_gui STATIC ${SOURCES} ${FORMS_HEADERS} ${RESOURCES})
target_link_libraries (${lib_gui} lib_font_size_generator)

qt5_use_modules (lib_gui Widgets)
