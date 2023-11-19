module synodic.honesty.test:test;

import :test;

namespace synodic::honesty
{
	Test<void>::Test(std::string_view name, std::move_only_function<void()> runner):
		BaseTest(name),
		runner_(std::move(runner))
	{
	}

	Test<void>& Test<void>::operator=(std::move_only_function<void()> runner)
	{
		runner_ = std::move(runner);
		return *this;
	}

	void Test<void>::Run()
	{
	}
}
