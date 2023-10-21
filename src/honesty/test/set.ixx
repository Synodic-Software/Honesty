
export module synodic.honesty.test:set;

import std;
import :test;

export namespace synodic::honesty
{
	template<typename T>
	constexpr auto expect(const T& expression)
	{
		return expression;
	}

	class TestSet
	{
	public:
		constexpr TestSet(std::string_view name);

		template<std::invocable Fn>
		constexpr TestSet(std::string_view name, Fn&& generator);

		template<std::invocable Fn>
		const TestSet& operator=(Fn&& generator) const;

	private:
		std::string_view name_;
	};

	constexpr TestSet::TestSet(std::string_view name) :
		name_(name)
	{
	}

	template<std::invocable Fn>
	constexpr TestSet::TestSet(std::string_view name, Fn&& generator) :
		name_(name)
	{
		// Propagate to the assignment operator
		*this = std::forward<Fn>(generator);
	}

	template<std::invocable Fn>
	const TestSet& TestSet::operator=(Fn&& generator) const
	{
		// Call the generator and register the tests
		std::forward<Fn>(generator)();
		return *this;
	}

	namespace literals
	{
		[[nodiscard]] constexpr auto operator""_test(const char* const name, std::size_t const size)
		{
			return Test(std::string_view(name, size));
		}

		[[nodiscard]] constexpr auto operator""_set(const char* const name, std::size_t const size)
		{
			return TestSet(std::string_view(name, size));
		}

		[[nodiscard]] constexpr auto operator""_i(unsigned long long int num)
		{
			return num;
		}
	}
}
