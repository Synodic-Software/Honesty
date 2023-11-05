import std;
import synodic.honesty.test;

using namespace synodic::honesty;
using namespace synodic::honesty::literals;

Suite suite(
	"suite",
	[]() -> TestGenerator
	{
		int count = 0;
		co_yield Test(
			"test",
			[&count]
			{
				++count;
			});

		co_yield "array"_test = [&count](const auto& parameter)
		{
			++count;
		} | std::tuple{3u, 4.0f};

		co_yield "array"_test = [&count]<typename T>(const T& parameter)
		{
			++count;
		} | std::array{3, 4};

		expect(count == 5);
	});
