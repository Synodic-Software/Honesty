
export module synodic.honesty.test:test;

import std;

export namespace synodic::honesty
{
	class Test
	{
	public:
		/**
		 * \brief Creates a test from a
		 * \param name
		 * \param runner
		 */
		Test(std::string_view name, std::move_only_function<void()> runner);

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
