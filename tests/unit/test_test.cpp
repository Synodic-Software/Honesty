import std;
import synodic.honesty.test;

using namespace synodic;
using namespace synodic::honesty::literals;

auto defaultTest = honesty::Test(
	"default",
	[]
	{
	});

auto callable = []
{
};

auto referenceTest = honesty::Test("reference", callable);

auto parameterizedTestTuple = honesty::Test(
	"tuple",
	std::tuple(3u, 4.0f),
	[](const auto& parameter)
	{
	});

auto parameterizedTestRange = honesty::Test(
	"array",
	std::array{3, 4},
	[](const auto& parameter)
	{
	});
