export module synodic.honesty.test:literals;

import :test;
import :suite;

export namespace synodic::honesty::literals
{
	[[nodiscard]] consteval auto operator""_test(const char* const name, std::size_t const size)
	{
		return Test(std::string_view(name, size));
	}

	[[nodiscard]] auto operator""_set(const char* const name, std::size_t const size)
	{
		return Suite(std::string_view(name, size));
	}
}
