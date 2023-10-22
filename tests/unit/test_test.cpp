import std;
import synodic.honesty.test;

using namespace synodic::honesty;
using namespace synodic::honesty::literals;

auto defaultTest = Test(
	"default",
	[]
	{
	});

auto callable = []
{
};

auto referenceTest = Test("reference", callable);

auto parameterizedTestTuple = Test(
	"tuple",
	std::tuple(3u, 4.0f),
	[](const auto& parameter)
	{
	});

auto parameterizedTestRange = Test(
	"array",
	std::array{3, 4},
	[](const auto& parameter)
	{
	});
