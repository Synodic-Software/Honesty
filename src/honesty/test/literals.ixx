export module synodic.honesty.test:literals;

import :test;
import :set;

namespace synodic::honesty::literals
{
	[[nodiscard]] constexpr auto operator""_test(const char* const name, std::size_t const size)
	{
		return Test(std::string_view(name, size));
	}

	[[nodiscard]] constexpr auto operator""_set(const char* const name, std::size_t const size)
	{
		return TestSet(std::string_view(name, size));
	}
}
