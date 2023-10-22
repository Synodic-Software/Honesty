export module synodic.honesty.test:suite;

import std;

export namespace synodic::honesty
{
	class Suite
	{
	public:
		explicit Suite(std::string_view name);
		Suite(std::string_view name, std::move_only_function<void()> generator);

		const Suite& operator=(std::move_only_function<void()> generator) const;

	private:
		std::string_view name_;
	};
}
