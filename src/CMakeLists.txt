
# Create the file sets that will be found in this directory and subdirectories

target_sources(honesty
	PUBLIC
		FILE_SET interfaces
		TYPE CXX_MODULES
		FILES
			"honesty.ixx"
)

target_sources(honesty
	PRIVATE
		FILE_SET implementations
		TYPE CXX_MODULES
)

target_sources(honesty_main
	PUBLIC
		FILE_SET interfaces
		TYPE CXX_MODULES
)

add_subdirectory(
	honesty
)
