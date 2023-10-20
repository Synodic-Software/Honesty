cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

project(tests
	DESCRIPTION "Tests for the honesty project"
	LANGUAGES CXX
)

add_executable(tests)
add_executable(tests_no_main)

set_target_properties(tests tests_no_main
	PROPERTIES
		LINKER_LANGUAGE CXX
		CXX_STANDARD 23
		CXX_STANDARD_REQUIRED ON
		CXX_EXTENSIONS NO
		FOLDER "tests"
)

target_link_libraries(tests
PRIVATE
	synodic::honesty::main
)

target_link_libraries(tests_no_main
PRIVATE
	synodic::honesty
)

add_subdirectory(
	unit
)