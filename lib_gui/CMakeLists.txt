cmake_minimum_required (VERSION 3.9)

set (CMAKE_AUTOMOC ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON)

find_package (Qt5Widgets REQUIRED)
find_package (Qt5Gui)
find_package (Qt5Core)

INCLUDE_DIRECTORIES (atm_widgets
		     features/animation
		     features/service
		     images
		     operation_widgets/description_menu
		     operation_widgets/initial_menu
		     operation_widgets/login_menu
		     operation_widgets/registration_menu
		     subwidgets
                     widgets_appearance
                     widgets_arrangement/common/modificators/composite
                     widgets_arrangement/common/modificators/primitive
                     widgets_arrangement/common/widgets_geometries
                     widgets_arrangement/splash_screen)

file (GLOB SOURCES "atm_widgets/*.cpp"
	           "features/animation/*.cpp"
	           "features/service/*.cpp"
	           "operation_widgets/description_menu/*.cpp"
	           "operation_widgets/initial_menu/*.cpp"
	           "operation_widgets/login_menu/*.cpp"
	           "operation_widgets/registration_menu/*.cpp"
	           "subwidgets/*.cpp"
                   "widgets_appearance/*.cpp"
                   "widgets_arrangement/common/modificators/composite/*.cpp"
                   "widgets_arrangement/common/modificators/primitive/*.cpp"
                   "widgets_arrangement/common/widgets_geometries/*.cpp"
                   "widgets_arrangement/splash_screen/*.cpp")

file (GLOB UI_HEADERS "atm_widgets/*.ui")

qt5_wrap_ui (FORMS_HEADERS ${UI_HEADERS})
qt5_add_resources (RESOURCES atm_resources.qrc)

set (GUI_LIBRARY_MESSAGE "Graphical library installed...\n")
message (${GUI_LIBRARY_MESSAGE})

add_library (lib_gui STATIC ${SOURCES} ${FORMS_HEADERS} ${RESOURCES})

qt5_use_modules (lib_gui Widgets)
