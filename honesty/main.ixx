
export module synodic.honesty:main;

import std;

namespace synodic::honesty
{
	enum class Mode
	{
		EXECUTE
	};
}

export namespace synodic::honesty
{
	int main(int argc, char* argv[])
	{
		// TODO: Parse inputs

		constexpr Mode mode = Mode::EXECUTE;

		try
		{
			switch (mode)
			{
				case Mode::EXECUTE :
				{
					break;
				}
				default :
				{
					std::terminate();
				}
			}

			return 0;
		}
		catch (const std::invalid_argument& exception)
		{
			std::println("Error: {0}", exception.what());

			return 1;
		}
	}
}
