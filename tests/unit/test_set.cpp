import std;
import synodic.honesty;

constexpr auto sum(auto... values)
{
	return (values + ...);
}


using namespace synodic;
using namespace synodic::honesty::literals;

auto set = honesty::Set(
	"test",
	[]
	{
		"Statement"_test = []
		{
			honesty::expect(true);
			honesty::expect(not false);
		};

		honesty::Test(
			"Statement",
			[]
			{
				honesty::expect(sum(0) == 0_i);
				honesty::expect(sum(1, 2) == 3_i);
				honesty::expect(sum(1, 2) > 0_i and 41_i == sum(40, 2));
			});
	});