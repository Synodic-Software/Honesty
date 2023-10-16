target_sources(honesty
	PUBLIC
		FILE_SET CXX_MODULES
		BASE_DIRS
			"${PROJECT_SOURCE_DIR}/honesty"
		FILES
			"honesty.ixx"
			"set.ixx"
			"set.cpp"
			"entry.ixx"
)

target_sources(honesty_main
	PUBLIC
		FILE_SET CXX_MODULES
		BASE_DIRS
			"${PROJECT_SOURCE_DIR}/honesty"
		FILES
			"main.cpp"
)