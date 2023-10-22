
export module synodic.honesty.test:test;

import std;

export namespace synodic::honesty
{
	class Test
	{
	public:

		Test(std::string_view name);

		/**
		 * \brief Creates a test from a
		 * \param name
		 * \param runner
		 */
		template<std::invocable Fn>
		Test(std::string_view name, Fn&& runner);

		template<std::ranges::range T, std::invocable<T&&> Fn>
		Test(std::string_view name, T&& data, Fn&& runner);

		template<typename... ParamTypes, typename Fn>
			requires(std::invocable<Fn, ParamTypes &&> && ...)
		Test(std::string_view name, std::tuple<ParamTypes...>&& data, Fn&& runner);

		Test& operator=(std::move_only_function<void()> runner);

	protected:
		std::string_view name_;
		std::move_only_function<void()> test_;
	};

	Test::Test(std::string_view name) :
		name_(name)
	{
	}

	template<std::invocable Fn>
	Test::Test(std::string_view name, Fn&& runner) :
		name_(name)
	{
		// Propagate to the assignment operator
		*this = std::forward<Fn>(runner);
	}

	template<std::ranges::range T, std::invocable<T&&> Fn>
	Test::Test(std::string_view name, T&& data, Fn&& runner)
	{
	}

	template<typename... ParamTypes, typename Fn>
		requires(std::invocable<Fn, ParamTypes &&> && ...)
	Test::Test(std::string_view name, std::tuple<ParamTypes...>&& data, Fn&& runner)
	{
	}
}
