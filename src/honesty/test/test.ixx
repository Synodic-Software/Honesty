
export module synodic.honesty.test:test;

import std;

export namespace synodic::honesty
{

	class Test
	{
	public:
		consteval Test(std::string_view name);

		template<std::invocable Fn>
		consteval Test(std::string_view name, Fn&& runner);

		template<std::invocable Fn>
		consteval const Test& operator=(Fn&& runner) const;

	private:
		std::string_view name_;
	};

	consteval Test::Test(std::string_view name) :
		name_(name)
	{
	}

	template<std::invocable Fn>
	consteval Test::Test(std::string_view name, Fn&& runner) :
		name_(name)
	{
		// Propagate to the assignment operator
		*this = std::forward<Fn>(runner);
	}

	template<std::invocable Fn>
	consteval const Test& Test::operator=(Fn&& runner) const
	{
		//registry().emplace_back(name_, std::make_unique<Runner<Fn>>(runner));
		return *this;
	}
}
