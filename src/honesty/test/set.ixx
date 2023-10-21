
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

	class Set
	{
	public:
		constexpr Set(std::string_view name);

		template<std::invocable Fn>
		constexpr Set(std::string_view name, Fn&& generator);

		template<std::invocable Fn>
		const Set& operator=(Fn&& generator) const;

	private:
		std::string_view name_;
	};

	constexpr Set::Set(std::string_view name) :
		name_(name)
	{
	}

	template<std::invocable Fn>
	constexpr Set::Set(std::string_view name, Fn&& generator) :
		name_(name)
	{
		// Propagate to the assignment operator
		*this = std::forward<Fn>(generator);
	}

	template<std::invocable Fn>
	const Set& Set::operator=(Fn&& generator) const
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
			return Set(std::string_view(name, size));
		}

		[[nodiscard]] constexpr auto operator""_i(unsigned long long int num)
		{
			return num;
		}
	}
}
