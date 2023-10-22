import std;
import synodic.honesty.test;

using namespace synodic::honesty;
using namespace synodic::honesty::literals;

Suite suite(
	"suite",
	[]() -> generator<Test>
	{
		co_yield "test"_test = []
		{
		};
	});
