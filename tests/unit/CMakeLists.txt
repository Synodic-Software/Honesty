target_sources(tests
PRIVATE
	test_expect.cpp
	test_set.cpp
)

# This test uses the library target that doesn't defined a main.
# It instantiates its own
target_sources(tests_no_main
PRIVATE
	test_main.cpp
)

add_test(NAME tests COMMAND tests)
add_test(NAME tests_no_main COMMAND tests_no_main)