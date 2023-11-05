
export module synodic.honesty.test:runner;
import std;
import :suite;
import :test;

export namespace synodic::honesty
{
	class Runner
	{
	public:
		class Suite final : public honesty::Suite
		{
		public:
			explicit Suite(honesty::Suite&& other) noexcept;

			TestGenerator Generate() const;
		};

		void Run();

		static std::vector<Suite>& Suites();
	};
}
