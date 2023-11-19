export module synodic.honesty.test:implementation;

import std;

export namespace synodic::honesty
{
	class BaseTest
	{
	public:
		BaseTest() = delete;
		virtual ~BaseTest() = default;

	protected:
		BaseTest(std::string_view name);

		friend class Runner;

		virtual void Run() = 0;

		std::string_view name_;
	};

}
