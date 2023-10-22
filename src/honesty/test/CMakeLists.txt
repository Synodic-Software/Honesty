target_sources(honesty
	PUBLIC
		FILE_SET interfaces
		FILES
			"set.ixx"
			"test.ixx"
			"entry.ixx"
			"runner.ixx"
			"expression.ixx"
			"literals.ixx"
			"reporter.ixx"
			"logger.ixx"
	PRIVATE
		FILE_SET implementations
		FILES
			"runner.cpp"
			"set.cpp"
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

add_subdirectory(
	reporter
)

add_subdirectory(
	logger
)