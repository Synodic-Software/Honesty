module synodic.honesty.test:runner;
import :runner;
import std;

namespace synodic::honesty
{
	Runner::Suite::Suite(honesty::Suite&& other) noexcept :
		honesty::Suite(std::move(other))
	{
	}

	generator<Test> Runner::Suite::Generate() const
	{
		return generator_();
	}

	Runner::Test::Test(honesty::Test&& other) noexcept :
		honesty::Test(std::move(other))
	{
	}

	void Runner::Test::Run()
	{
		runner_();
	}

	void Runner::Run()
	{
		const auto& suites = Suites();
		for (const Suite& suite: suites)
		{
			auto generator = suite.Generate();
			for (auto& test: generator)
			{
				Test testWrapper(std::move(test));

				testWrapper.Run();
			}
		}
	}

	std::vector<Runner::Suite>& Runner::Suites()
	{
		static std::vector<Suite> suites;

		return suites;
	}
}
