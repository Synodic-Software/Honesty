target_sources(honesty
	PUBLIC
		FILE_SET CXX_MODULES
		BASE_DIRS
			"${PROJECT_SOURCE_DIR}/honesty"
		FILES
			"test.ixx"
)