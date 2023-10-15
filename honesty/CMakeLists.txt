target_sources(honesty
	PUBLIC
		FILE_SET CXX_MODULES
		BASE_DIRS
			"${PROJECT_SOURCE_DIR}/honesty"
		FILES
			"honesty.ixx"
			"main.ixx"
			"set.ixx"
			"set.cpp"
)