export module synodic.honesty.test.logger;

export import :stdout;

export namespace synodic::honesty
{
	template<typename T>
	concept is_logger = true;
}