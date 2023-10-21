
export module synodic.honesty.test:expression;

export namespace synodic::honesty
{
	template<typename T>
	constexpr auto expect(const T& expression)
	{
		return expression;
	}
}
