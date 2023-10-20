target_sources(honesty
	PUBLIC
		FILE_SET public_test
		TYPE CXX_MODULES
		BASE_DIRS
			"${PROJECT_SOURCE_DIR}/src"
		FILES
			"set.ixx"
			"test.ixx"
			"entry.ixx"
			"runner.ixx"
	PRIVATE
		FILE_SET private_test
		TYPE CXX_MODULES
		BASE_DIRS
			"${PROJECT_SOURCE_DIR}/src"
		FILES
			"set.cpp"
			"test.cpp"
			"entry.cpp"
			"runner.cpp"
)

target_sources(honesty_main
	PUBLIC
		FILE_SET test_main
		TYPE CXX_MODULES
		BASE_DIRS
			"${PROJECT_SOURCE_DIR}/src"
		FILES
			"main.cpp"
)