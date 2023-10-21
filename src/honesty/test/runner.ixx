
export module synodic.honesty.test:runner;
import std;

export namespace synodic::honesty
{
	class BaseRunner
	{
	public:
		virtual ~BaseRunner() = default;
		virtual void Run()	  = 0;
	};

	template<std::invocable Fn>
	class Runner final : public BaseRunner
	{
	public:
		void Run() override;

		explicit Runner(std::convertible_to<Fn> auto&& func);

	private:
		Fn function_;
	};

	template<std::invocable Fn>
	void Runner<Fn>::Run()
	{
		function_();
	}

	template<std::invocable Fn>
	Runner<Fn>::Runner(std::convertible_to<Fn> auto&& func) :
		function_(std::forward<decltype(func)>(func))
	{
	}
}
