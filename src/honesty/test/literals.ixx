export module synodic.honesty.test:literals;

import :test;
import :suite;
import :generator;

export namespace synodic::honesty::literals
{
	[[nodiscard]] TestGenerator operator""_test(const char* const name, std::size_t const size)
	{
		auto callable = []
		{
			throw std::invalid_argument("The test must be assigned an a function to execute");
		};

		co_yield Test(std::string_view(name, size), callable);
	}
}
