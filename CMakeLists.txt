cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

project(honesty
	VERSION 0.1.0
	DESCRIPTION "Honesty"
	LANGUAGES CXX
)

option(BUILD_TESTING "Build test programs" ON)

# Provide the library definition
add_library(honesty STATIC)
add_library(synodic::honesty ALIAS honesty)

# Provide a convenience library for main
add_library(honesty_main STATIC)
add_library(synodic::honesty::main ALIAS honesty_main)

set_target_properties(honesty honesty_main
	PROPERTIES
		LINKER_LANGUAGE CXX
		CXX_STANDARD 23
		CXX_STANDARD_REQUIRED ON
		CXX_EXTENSIONS NO
)

target_link_libraries(honesty_main
PRIVATE
	synodic::honesty
)

add_subdirectory(
	"honesty"
)

if(BUILD_TESTING)

	# Do not include CTest because it adds targets and integrations we do not support
	enable_testing()

    add_subdirectory(
		"tests"
	)

endif()