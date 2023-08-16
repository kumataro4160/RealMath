export module realmath.floor;

export import realmath.basic;

export namespace kuma
{
	constexpr whole_t floor(float32_t x)noexcept
	{
		const whole_t xWhole = static_cast<whole_t>(x);
		return xWhole + (x < static_cast<float32_t>(xWhole) ? -1LL : 0LL);
	}

	constexpr whole_t floor(float64_t x)noexcept
	{
		const whole_t xWhole = static_cast<whole_t>(x);
		return xWhole + (x < static_cast<float64_t>(xWhole) ? -1LL : 0LL);
	}
}