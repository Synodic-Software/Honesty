target_sources(honesty
	PUBLIC
		FILE_SET public_honesty
		TYPE CXX_MODULES
		BASE_DIRS
			"${PROJECT_SOURCE_DIR}/src"
		FILES
			"benchmark.ixx"
			"profile.ixx"
			"test.ixx"
)

add_subdirectory(
	benchmark
)

add_subdirectory(
	profile
)

add_subdirectory(
	test
)