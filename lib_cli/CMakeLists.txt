cmake_minimum_required (VERSION 3.9)

set (CMAKE_BUILD_TYPE Release)

INCLUDE_DIRECTORIES (messengers
                     messengers/registration_messengers
                     messengers/registration_messengers/confirmation_animation
		     output
		     user_input_handling
                     view_model
                     system_dependencies)

file (GLOB SOURCES "messengers/*.cpp"
                   "messengers/registration_messengers/*.cpp"
                   "messengers/registration_messengers/confirmation_animation/*.cpp"
                   "output/*.cpp"
		   "user_input_handling/*.cpp"
                   "view_model/*.cpp"
                   "system_dependencies/*.cpp")

set (CLI_LIBRARY_MESSAGE "Console library installed...")
message (${CLI_LIBRARY_MESSAGE})

add_library (lib_cli STATIC ${SOURCES})
