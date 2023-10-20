target_sources(honesty
	PUBLIC
		FILE_SET public_profile
		TYPE CXX_MODULES
		BASE_DIRS
			"${PROJECT_SOURCE_DIR}/src"
		FILES
	PRIVATE
		FILE_SET private_profile
		TYPE CXX_MODULES
		BASE_DIRS
			"${PROJECT_SOURCE_DIR}/src"
		FILES
)
