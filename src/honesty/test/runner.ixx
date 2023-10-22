
export module synodic.honesty.test:runner;
import std;
import :set;

export namespace synodic::honesty
{
	class Runner final
	{
	public:
		void Run() const;

		static std::vector<TestSet>& Suites();

	private:
	};

	void Runner::Run() const
	{
		const auto& suites = Suites();
		for (const TestSet& set: suites)
		{
		}
	}

	std::vector<TestSet>& Runner::Suites()
	{
		static std::vector<TestSet> suites;

		return suites;
	}
}
