
export module synodic.honesty.test:test;

import std;

export namespace synodic::honesty
{
	class Test
	{
	public:
		consteval Test(std::string_view name);

		/**
		 * \brief Creates a test from a
		 * \param name
		 * \param runner
		 */
		template<std::invocable Fn>
		consteval Test(std::string_view name, Fn&& runner);

		template<std::ranges::range T, std::invocable<T&&> Fn>
		consteval Test(std::string_view name, T&& data, Fn&& runner);

		template<typename... ParamTypes, typename Fn>
			requires(std::invocable<Fn, ParamTypes &&> && ...)
		consteval Test(std::string_view name, std::tuple<ParamTypes...>&& data, Fn&& runner);

		template<std::invocable Fn>
		consteval const Test& operator=(Fn&& runner) const;

	private:
		std::string_view name_;
	};

	consteval Test::Test(std::string_view name) :
		name_(name)
	{
	}

	template<std::invocable Fn>
	consteval Test::Test(std::string_view name, Fn&& runner) :
		name_(name)
	{
		// Propagate to the assignment operator
		*this = std::forward<Fn>(runner);
	}

	template<std::ranges::range T, std::invocable<T&&> Fn>
	consteval Test::Test(std::string_view name, T&& data, Fn&& runner)
	{
	}

	template<typename... ParamTypes, typename Fn>
		requires(std::invocable<Fn, ParamTypes &&> && ...)
	consteval Test::Test(std::string_view name, std::tuple<ParamTypes...>&& data, Fn&& runner)
	{
	}

	template<std::invocable Fn>
	consteval const Test& Test::operator=(Fn&& runner) const
	{
		return *this;
	}
}
