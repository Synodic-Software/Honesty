cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

project(honesty
	VERSION 0.1.0
	DESCRIPTION "Honesty"
	LANGUAGES CXX
)

option(BUILD_TESTING "Build test programs" ON)

# Provide a namespaced alias
add_library(honesty STATIC)
add_library(synodic::honesty ALIAS honesty)

set_target_properties(honesty
	PROPERTIES
		LINKER_LANGUAGE CXX
		CXX_STANDARD 23
		CXX_STANDARD_REQUIRED ON
		CXX_EXTENSIONS NO
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