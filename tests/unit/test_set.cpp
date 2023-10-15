import std;
import synodic.honesty;

const auto set = synodic::honesty::Set
{
	"test", []
	{
		"Statement"_test = {synodic::honesty::expect(true)};
	}
};