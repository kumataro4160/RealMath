export module realmath.sign;

export import realmath.basic;

export namespace kuma
{
	constexpr sign_t sign(float32_t x)noexcept
	{
		return x > 0.0f ? 1 : (x < -0.0f ? -1 : 0);
	}

	constexpr sign_t sign(float64_t x)noexcept
	{
		return x > 0.0 ? 1 : (x < -0.0 ? -1 : 0);
	}
}