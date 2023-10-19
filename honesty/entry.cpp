module synodic.honesty:entry;

import std;
import :test;

namespace synodic::honesty
{
	int entry()
	{
		auto& reg = registry();
		for (auto& testCase: reg)
		{
		}

		return 0;
	}
}