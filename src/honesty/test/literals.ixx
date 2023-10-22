export module synodic.honesty.test:literals;

import :test;
import :set;

export namespace synodic::honesty::literals
{
	[[nodiscard]] consteval auto operator""_test(const char* const name, std::size_t const size)
	{
		return Test(std::string_view(name, size));
	}

	[[nodiscard]] auto operator""_set(const char* const name, std::size_t const size)
	{
		return TestSet(std::string_view(name, size));
	}
}
