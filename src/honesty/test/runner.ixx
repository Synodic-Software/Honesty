
export module synodic.honesty.test:runner;
import std;
import :set;

export namespace synodic::honesty
{

	class Runner final
	{
	public:
		void Run();

	private:
		std::vector<TestSet> suites_;
	};

	void Runner::Run()
	{
		for (const TestSet& set: suites_)
		{
		}
	}
}
