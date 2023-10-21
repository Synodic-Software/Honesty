
export module synodic.honesty.test:set;

import std;

export namespace synodic::honesty
{
	class TestSet
	{
	public:
		consteval TestSet(std::string_view name);

		template<std::invocable Fn>
		consteval TestSet(std::string_view name, Fn&& generator);

		template<std::invocable Fn>
		consteval const TestSet& operator=(Fn&& generator) const;

	private:
		std::string_view name_;
	};

	consteval TestSet::TestSet(std::string_view name) :
		name_(name)
	{
	}

	template<std::invocable Fn>
	consteval TestSet::TestSet(std::string_view name, Fn&& generator) :
		name_(name)
	{
		// Propagate to the assignment operator
		*this = std::forward<Fn>(generator);
	}

	template<std::invocable Fn>
	consteval const TestSet& TestSet::operator=(Fn&& generator) const
	{
		// Call the generator and register the tests
		std::forward<Fn>(generator)();
		return *this;
	}
}
