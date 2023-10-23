export module synodic.honesty.test:suite;
export import generator;

import std;

import :test;

export namespace synodic::honesty
{
	class Suite
	{
	public:
		Suite(std::string_view name, std::move_only_function<generator<Test>() const> generator);

		Suite(const Suite& other)	  = delete;
		Suite(Suite&& other) noexcept = default;

		Suite& operator=(const Suite& other)	 = delete;
		Suite& operator=(Suite&& other) noexcept = delete;

	protected:
		std::string_view name_;
		std::move_only_function<generator<Test>() const> generator_;
	};
}
