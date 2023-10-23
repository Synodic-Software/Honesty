module synodic.honesty.test:suite;

import std;

import :suite;
import :runner;

namespace synodic::honesty
{
	Suite::Suite(std::string_view name, std::move_only_function<generator<Test>() const> generator) :
		name_(std::move(name)),
		generator_(std::move(generator))
	{
		Runner::Suites().emplace_back(std::move(*this));
	}
}
