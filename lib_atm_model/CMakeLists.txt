cmake_minimum_required (VERSION 3.9)

set (CMAKE_BUILD_TYPE Release)

INCLUDE_DIRECTORIES (atm_operations
                     credit_calculator
		     credit_department
		     incoming_data_handling
		     interaction
                     interface_presenter
	             user_data)

file (GLOB SOURCES "atm_operations/*.cpp"
                   "credit_calculator/*.cpp"
		   "credit_department/*.cpp"
	           "incoming_data_handling/*.cpp"
		   "interaction/*.cpp"
		   "interface_presenter/*.cpp"
                   "user_data/*.cpp")

set (ATM_CORE_MESSAGE "\nAtm Core library installed...")
message (${ATM_CORE_MESSAGE})

add_library (lib_atm_model STATIC ${SOURCES})
