import std;
import synodic.honesty.test;

using namespace synodic;
using namespace synodic::honesty::literals;

honesty::TestSet set = honesty::TestSet(
	"set",
	[]
	{
		"test"_test = []
		{
		};
	});
