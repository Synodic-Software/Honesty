module synodic.honesty.test:test;

import :test;

namespace synodic::honesty
{
	Test& Test::operator=(std::move_only_function<void()> runner)
	{
		test_ = std::move(runner);
		return *this;
	}
}
