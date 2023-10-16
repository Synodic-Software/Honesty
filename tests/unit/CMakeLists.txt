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

add_test(NAME tests COMMAND $<TARGET_FILE:tests> -E echo tests)
add_test(NAME tests_no_main COMMAND $<TARGET_FILE:tests_no_main> -E echo tests_no_main)