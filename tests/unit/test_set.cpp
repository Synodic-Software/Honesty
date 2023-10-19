import std;
import synodic.honesty;

using namespace synodic;
using namespace synodic::honesty::literals;

auto set = honesty::Set(
	"test",
	[]
	{
		"Statement"_test = []
		{
			honesty::expect(true);
		};

		honesty::Test(
			"Statement",
			[]
			{
				std::print("Test");
			});
	});