export module synodic.honesty.test:set;

import std;

export namespace synodic::honesty
{
	class TestSet
	{
	public:
		explicit TestSet(std::string_view name);
		TestSet(std::string_view name, std::move_only_function<void()> generator);

		const TestSet& operator=(std::move_only_function<void()> generator) const;

	private:
		std::string_view name_;
	};
}
