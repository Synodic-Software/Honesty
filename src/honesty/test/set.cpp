module synodic.honesty.test:set;

import std;

namespace synodic::honesty
{
	TestSet::TestSet(std::string_view name) :
		name_(name)
	{
	}

	TestSet::TestSet(std::string_view name, std::move_only_function<void()> generator) :
		name_(name)
	{
		// Propagate to the assignment operator
		*this = std::move(generator);
	}

	const TestSet& TestSet::operator=(std::move_only_function<void()> generator) const
	{
		// Call the generator and register the tests
		// std::generator<Test> generator();
		return *this;
	}
}
