target_sources(honesty
	PUBLIC
		FILE_SET interfaces
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