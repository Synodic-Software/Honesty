
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

			generator<Test> Generate() const;
		private:
		};

		class Test final : public honesty::Test
		{
		public:
			explicit Test(honesty::Test&& other) noexcept;

			void Run();
		};

		void Run();

		static std::vector<Suite>& Suites();

	private:
	};
}
