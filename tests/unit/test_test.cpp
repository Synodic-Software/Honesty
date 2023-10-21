import std;
import synodic.honesty.test;

using namespace synodic;
using namespace synodic::honesty::literals;

auto literalTest = "Statement"_test = []
{
};

auto defaultTest = honesty::Test(
	"Statement",
	[]
	{
	});

auto callable = []
{
};

auto referenceTest = honesty::Test("Statement", callable);
