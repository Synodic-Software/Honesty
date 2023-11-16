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

	/**
	 * @brief Literal that generates an empty suite that must be assigned a closure for test generation
	 * @param name The name of the suite
	 * @param size The size of the name of the suite
	 * @return A suite object
	 */
	[[nodiscard]] Suite operator""_suite(const char* const name, std::size_t const size)
	{
		//Suite(std::string_view(name, size));
		return Suite(std::string_view(name, size));
	}
}
