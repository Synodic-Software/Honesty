target_sources(tests
PRIVATE
	test_expect.cpp
	test_suite.cpp
	test_test.cpp
	test_entry.cpp
)

add_test(NAME tests COMMAND tests)
