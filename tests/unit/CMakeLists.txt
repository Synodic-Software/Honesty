target_sources(tests
PRIVATE
	test_main.cpp
	test_set.cpp
)

add_test(NAME tests COMMAND tests)