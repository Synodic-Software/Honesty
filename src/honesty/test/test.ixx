
export module synodic.honesty.test:test;

import std;
import generator;

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

		Test& operator=(std::move_only_function<void()> runner);

	protected:
		std::string_view name_;
		std::move_only_function<void()> test_;
	};

	template<typename... ParamTypes>
	class ParameterizedTest
	{
	public:
		template<std::ranges::range T, std::invocable<T&&> Fn>
		ParameterizedTest(std::string_view name, T&& data, Fn&& runner);

		template<typename Fn>
			requires(std::invocable<Fn, ParamTypes &&> && ...)
		ParameterizedTest(std::string_view name, std::tuple<ParamTypes...>&& data, Fn&& runner);

		const generator<Test> operator=(const ParameterizedTest& test) const;

	private:
		std::tuple<ParamTypes...> parameters;
	};


	template<typename... ParamTypes>
	template<std::ranges::range T, std::invocable<T&&> Fn>
	ParameterizedTest<ParamTypes...>::ParameterizedTest(std::string_view name, T&& data, Fn&& runner)
	{
	}

	template<typename... ParamTypes>
	template<typename Fn>
		requires(std::invocable<Fn, ParamTypes &&> && ...)
	ParameterizedTest<ParamTypes...>::ParameterizedTest(
		std::string_view name,
		std::tuple<ParamTypes...>&& data,
		Fn&& runner)
	{
	}

	template<typename ... ParamTypes>
	const generator<Test> ParameterizedTest<ParamTypes...>::operator=(const ParameterizedTest& test) const
	{
		return test;
	}
}
