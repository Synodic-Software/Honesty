
export module synodic.honesty:test;

import :runner;
import std;

export namespace synodic::honesty
{
	class TestRunner
	{
	public:
		constexpr TestRunner(std::string_view name, std::unique_ptr<BaseRunner> runner);

		void Run() const;

	private:
		std::string_view name_;
		std::unique_ptr<BaseRunner> runner_;
	};

	void TestRunner::Run() const
	{
		runner_->Run();
	}

	constexpr TestRunner::TestRunner(std::string_view name, std::unique_ptr<BaseRunner> runner) :
		name_(name),
		runner_(std::move(runner))
	{
	}

	std::vector<TestRunner>& registry() noexcept
	{
		static std::vector<TestRunner> data;
		return data;
	}

	class Test
	{
	public:
		constexpr Test(std::string_view name);

		template<std::invocable Fn>
		constexpr Test(std::string_view name, Fn&& runner);

		template<std::invocable Fn>
		const Test& operator=(Fn&& runner) const;

	private:
		std::string_view name_;
	};

	constexpr Test::Test(std::string_view name) :
		name_(name)
	{
	}

	template<std::invocable Fn>
	constexpr Test::Test(std::string_view name, Fn&& runner) :
		name_(name)
	{
		// Propagate to the assignment operator
		*this = std::forward<Fn>(runner);
	}

	template<std::invocable Fn>
	const Test& Test::operator=(Fn&& runner) const
	{
		registry().emplace_back(name_, std::make_unique<Runner<Fn>>(runner));
		return *this;
	}
}
