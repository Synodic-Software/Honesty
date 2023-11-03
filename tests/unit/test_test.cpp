// These tests are not executed, so they exist to test the compilation of tests

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

auto parameterizedTestTuple = ParameterizedTest(
	"tuple",
	std::tuple(3u, 4.0f),
	[](const auto& parameter)
	{
	});

auto parameterizedTestRange = ParameterizedTest(
	"array",
	std::array{3, 4},
	[](const auto& parameter)
	{
	});

auto parameterizedTypeTest = ParameterizedTest(
	"type",
	std::tuple(3u, 4.0f),
	[]<typename T>(T input)
	{
	});

auto helperScope = []
{
	"literal"_test = []
	{
	};

	for (auto i: std::vector{1, 2, 3})
	{
		"parameterized"_test = [i]
		{
		};
	}
};