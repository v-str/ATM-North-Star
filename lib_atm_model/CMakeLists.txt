cmake_minimum_required (VERSION 3.0)

set (CMAKE_BUILD_TYPE Release)

INCLUDE_DIRECTORIES (atm_operations
                     credit_calculator
		     incoming_data_handling
		     interaction
                     interface_presenter
	             user_data)

file (GLOB_RECURSE SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

set (ATM_CORE_MESSAGE "\nAtm Core library installed...")
message (${ATM_CORE_MESSAGE})

add_library (lib_atm_model STATIC ${SOURCES})
