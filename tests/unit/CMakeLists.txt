target_sources(tests
PRIVATE
	test_expect.cpp
	test_set.cpp
	test_test.cpp
	test_entry.cpp
	test_expression.cpp
)

add_test(NAME tests COMMAND tests)
