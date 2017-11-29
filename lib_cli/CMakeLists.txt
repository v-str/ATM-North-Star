cmake_minimum_required (VERSION 3.0)

set (CMAKE_BUILD_TYPE Release)

INCLUDE_DIRECTORIES (messengers
                     messengers/registration_messengers
                     messengers/credit_calculator_messengers
                     messengers/registration_messengers/confirmation_animation
		     output
                     user_input_handling
                     view_model
                     system_dependencies)

file (GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

set (CLI_LIBRARY_MESSAGE "Console library installed...")
message (${CLI_LIBRARY_MESSAGE})

add_library (lib_cli STATIC ${SOURCES})
