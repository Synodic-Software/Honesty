module synodic.honesty.test:test;

import :test;

namespace synodic::honesty
{
	Test::Test(std::string_view name, std::move_only_function<void()> runner) :
		name_(name)
	{
		// Propagate to the assignment operator
		*this = std::move(runner);
	}

	Test& Test::operator=(std::move_only_function<void()> runner)
	{
		test_ = std::move(runner);
		return *this;
	}
}
