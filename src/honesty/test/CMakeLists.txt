target_sources(honesty
	PUBLIC
		FILE_SET interfaces
		FILES
			"set.ixx"
			"test.ixx"
			"entry.ixx"
			"runner.ixx"
			"expression.ixx"
	PRIVATE
		FILE_SET implementations
		FILES
			"set.cpp"
			"test.cpp"
			"entry.cpp"
			"runner.cpp"
)

target_sources(honesty_main
	PUBLIC
		FILE_SET interfaces
		FILES
			"main.cpp"
)

add_subdirectory(
	expression
)
