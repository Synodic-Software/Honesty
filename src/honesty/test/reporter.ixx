export module synodic.honesty.test.reporter;

export import :stdout;

export namespace synodic::honesty
{
	template<typename T>
	concept is_reporter = true;
}