
export module synodic.honesty.test:test;

import std;
import :generator;
import :implementation;

export namespace synodic::honesty
{
	template<typename T>
	class Test final : public BaseTest
	{
	public:
		Test(std::string_view name, std::move_only_function<void(const T&)> runner);

		Test& operator=(std::move_only_function<void(const T&)> runner);

	protected:
		void Run() override;

		std::move_only_function<void(const T&)> runner_;
	};

	template<>
	class Test<void> final : public BaseTest
	{
	public:
		Test(std::string_view name, std::move_only_function<void()> runner);

		Test& operator=(std::move_only_function<void()> runner);

	protected:
		void Run() override;

	private:
		std::move_only_function<void()> runner_;
	};

	template<typename T>
	Test<T>::Test(std::string_view name, std::move_only_function<void(const T&)> runner) :
		BaseTest(name),
		runner_(std::move(runner))
	{
	}

	template<typename T>
	Test<T>& Test<T>::operator=(std::move_only_function<void(const T&)> runner)
	{
		runner_ = std::move(runner);
		return *this;
	}

	template<typename T>
	void Test<T>::Run()
	{
	}

	// Template Deductions

	Test(std::string_view, std::move_only_function<void()>) -> Test<void>;

	template<typename T>
	Test(std::string_view, std::move_only_function<void(const T&)>) -> Test<T>;

	// Operators

	template<std::invocable Fn>
	[[nodiscard]] constexpr TestGenerator operator|(const Fn&& test, const std::ranges::range auto& range)
	{
		return [&test, &range]
		{
			for (const auto& arg: range)
			{
				co_yield Test("",test);
			}
		};
	}

	template<std::invocable Fn, typename... Types>
	[[nodiscard]] constexpr TestGenerator operator|(const Fn&& test, std::tuple<Types...>&& tuple)
	{
		return [&test, &tuple](const auto name)
		{
			apply(
				[test, name](const auto&... args)
				{
					(co_yield Test("",test), ...);
				},
				test);
		};
	}

}
