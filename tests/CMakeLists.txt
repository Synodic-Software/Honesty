cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

project(tests
	DESCRIPTION "Tests for the honesty project"
	LANGUAGES CXX
)

add_executable(tests)

set_target_properties(tests
	PROPERTIES
		LINKER_LANGUAGE CXX
		CXX_STANDARD 23
		CXX_STANDARD_REQUIRED ON
		CXX_EXTENSIONS NO
)

target_link_libraries(tests
PRIVATE
	synodic::honesty::main
)

add_subdirectory(
	unit
)

# Glob all files to add a source group tree
file(GLOB_RECURSE file_list ${CMAKE_CURRENT_SOURCE_DIR}/*)

# Must be called from the target definition directory. Only matched against target source files (No nested CMakeList.txt, docs, etc).
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${file_list})

# Make the 'tests' project the default startup
set_property(
	DIRECTORY
		${CMAKE_CURRENT_SOURCE_DIR}
	PROPERTY
		VS_STARTUP_PROJECT tests
)