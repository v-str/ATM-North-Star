cmake_minimum_required (VERSION 3.9)

set (CMAKE_CXX_STANDARD 11)

set (PROJECT_NAME AtmNorthStar)
project (${PROJECT_NAME})

set (CMAKE_AUTOMOC ON)
set (CMAKE_INCLUDE_CURRENT_DIR ON)

find_package (Qt5Widgets REQUIRED)

INCLUDE_DIRECTORIES (application/application_launch
                     application/interface_presenter
                     application/interface_presenter/console_presenter
                     lib_atm_model/atm_operations
                     lib_atm_model/credit_calculator
                     lib_atm_model/credit_department
                     lib_atm_model/incoming_data_handling
                     lib_atm_model/interaction
                     lib_atm_model/interface_presenter
                     lib_atm_model/user_data
                     lib_cli/messengers
                     lib_cli/messengers/registration_messengers
                     lib_cli/messengers/credit_messengers
                     lib_cli/messengers/registration_messengers/confirmation_animation
                     lib_cli/output
                     lib_cli/user_input
                     lib_cli/view_model
                     lib_cli/system_dependencies
                     lib_gui/atm_widgets
                     lib_gui/features/animation
                     lib_gui/features/service
                     lib_gui/images
                     lib_gui/operation_widgets/description_menu
                     lib_gui/operation_widgets/initial_menu
                     lib_gui/operation_widgets/login_menu
                     lib_gui/operation_widgets/registration_menu
                     lib_gui/subwidgets
                     lib_gui/widgets_appearance
                     lib_gui/widgets_arrangement/common/modificators/composite
                     lib_gui/widgets_arrangement/common/modificators/primitive
                     lib_gui/widgets_arrangement/common/widgets_geometries
                     lib_gui/widgets_arrangement/splash_screen)

set (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR})

add_subdirectory (lib_atm_model)
add_subdirectory (lib_cli)
add_subdirectory (lib_gui)

file (GLOB SOURCES "application/application_launch/*.cpp"
                   "application/interface_presenter/*.cpp"
                   "application/interface_presenter/console_presenter/*.cpp")

add_executable (${PROJECT_NAME} ${SOURCES})

target_link_libraries (${PROJECT_NAME} lib_atm_model lib_cli lib_gui)
