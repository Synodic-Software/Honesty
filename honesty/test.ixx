
export module synodic.honesty:test;

import std;

export namespace synodic::honesty
{
	class Test;

	std::vector<Test>& registry() noexcept
	{
		static std::vector<Test> data;
		return data;
	}

	class Test
	{
	public:
		template<std::invocable Fn>
		constexpr Test(std::string_view name, Fn&& runner);

		template<std::invocable Fn>
		const Test& operator=(Fn&& runner) const;

	private:
		std::string_view name_;
	};

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
		registry().emplace_back(name_, runner);
		return *this;
	}
}
