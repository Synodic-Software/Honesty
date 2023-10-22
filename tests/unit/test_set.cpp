import std;
import synodic.honesty.test;

using namespace synodic;
using namespace synodic::honesty::literals;

honesty::Suite suite = honesty::Suite(
	"suite",
	[]
	{
		"test"_test = []
		{
		};
	});
