
export module synodic.honesty:set;

import std;

export namespace synodic::honesty
{

	template<typename T>
	constexpr auto expect(const T& expression)
	{
		return expression;
	}

	class Test
	{
	public:
		template<std::invocable Fn>
		constexpr Test(std::string_view name, Fn&& runner);

		const Test& operator=(std::invocable auto&& runner) const
		{
			return *this;
		}
	};

	template<std::invocable Fn>
	constexpr Test::Test(std::string_view name, Fn&& runner)
	{
		// Propagate to the assignment operator
		*this = std::forward<Fn>(runner);
	}

	class Set
	{
	public:
		constexpr Set(std::string_view name, std::invocable auto&& generator);
	};

	constexpr Set::Set(std::string_view name, std::invocable auto&& generator)
	{
	}

	namespace literals
	{
		[[nodiscard]] constexpr auto operator""_test(const char* const name, std::size_t const size)
		{
			return Test(
				std::string_view(name, size),
				[]
				{
				});
		}
	}
}
