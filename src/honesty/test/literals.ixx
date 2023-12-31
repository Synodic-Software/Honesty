export module synodic.honesty.test:literals;

import :test;
import :suite;
import :generator;

export namespace synodic::honesty::literals
{
	//[[nodiscard]] consteval TestGenerator operator""_test(const char* const name, const std::size_t size)
	//{
	//	auto callable = []
	//	{
	//		throw std::invalid_argument("The test must be assigned a function to execute");
	//	};

	//	co_yield Test(std::string_view(name, size), callable);
	//}

	[[nodiscard]] consteval auto operator""_suite(const char* const name, const std::size_t size)
	{
		return Suite(std::string_view(name, size));
	}
}
