import std;
import synodic.honesty.test;

using namespace synodic::honesty;
using namespace synodic::honesty::literals;

Suite suite(
	"suite",
	[]() -> generator<Test>
	{
		co_yield Test(
			"test",
			[]
			{
			});

		//co_yield ParameterizedTest(
		//	"array",
		//	std::array{3, 4},
		//	[](const auto& parameter)
		//	{
		//	});
	});
