
export module synodic.honesty.test:runner;
import std;
import :suite;

export namespace synodic::honesty
{
	class Runner final
	{
	public:
		void Run() const;

		static std::vector<Suite>& Suites();

	private:
	};

	void Runner::Run() const
	{
		const auto& suites = Suites();
		for (const Suite& suite: suites)
		{
		}
	}

	std::vector<Suite>& Runner::Suites()
	{
		static std::vector<Suite> suites;

		return suites;
	}
}
