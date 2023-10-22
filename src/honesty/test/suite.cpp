module synodic.honesty.test:suite;

import std;
import :suite;

namespace synodic::honesty
{
	Suite::Suite(std::string_view name) :
		name_(name)
	{
	}

	Suite::Suite(std::string_view name, std::move_only_function<void()> generator) :
		name_(name)
	{
		// Propagate to the assignment operator
		*this = std::move(generator);
	}

	const Suite& Suite::operator=(std::move_only_function<void()> generator) const
	{
		// Call the generator and register the tests
		// std::generator<Test> generator();
		return *this;
	}
}
