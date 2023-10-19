
export module synodic.honesty:set;

import std;
import :test;

export namespace synodic::honesty
{
	template<typename T>
	constexpr auto expect(const T& expression)
	{
		return expression;
	}

	class Set
	{
	public:
		template<std::invocable Fn>
		constexpr Set(std::string_view name, Fn&& generator);

		template<std::invocable Fn>
		const Set& operator=(Fn&& generator) const;
	};

	template<std::invocable Fn>
	constexpr Set::Set(std::string_view name, Fn&& generator)
	{
		// Propagate to the assignment operator
		*this = std::forward<Fn>(generator);
	}

	template<std::invocable Fn>
	const Set& Set::operator=(Fn&& generator) const
	{
		std::forward<Fn>(generator)();
		return *this;
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
