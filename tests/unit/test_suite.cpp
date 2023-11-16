import std;
import synodic.honesty.test;

using namespace synodic::honesty;
using namespace synodic::honesty::literals;

auto innerSuiteGenerator = []() -> TestGenerator
{
	co_return;
};


auto suiteGenerator = []() -> TestGenerator
{
	// Tests that creation via literal works
	"inner literal"_suite = []() -> TestGenerator
	{
		//int count = 0;
		//co_yield Test(
		//	"test",
		//	[&count]
		//	{
		//		++count;
		//	});

		//co_yield "yes"_test = [&count]()
		//{
		//	++count;
		//};

		//co_yield "array"_test = [&count](const auto& parameter)
		//{
		//	++count;
		//} | std::tuple {3u, 4.0f};

		//co_yield "array"_test = [&count]<typename T>(const T& parameter)
		//{
		//	++count;
		//} | std::array {3, 4};

		co_return;
	};

	// Tests that nested suite via static creation work
	Suite suite("inner", innerSuiteGenerator);

	co_return;
};

// Static creation
Suite suite("outer", suiteGenerator);
