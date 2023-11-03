export module synodic.honesty.test:literals;

import :test;
import :suite;

export namespace synodic::honesty::literals
{
	[[nodiscard]] auto operator""_test(const char* const name, std::size_t const size)
	{
		auto callable = []
		{
			throw std::invalid_argument("The test must be assigned an a function to execute");
		};

		return Test(std::string_view(name, size), callable);
	}
}