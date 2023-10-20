target_sources(honesty
	PUBLIC
		FILE_SET public_src
		TYPE CXX_MODULES
		BASE_DIRS
			"${PROJECT_SOURCE_DIR}/src"
		FILES
			"honesty.ixx"
)

add_subdirectory(
	honesty
)