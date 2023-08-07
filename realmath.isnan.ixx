export module realmath.isnan;

export import realmath.basic;

export namespace realmath
{
	constexpr float32_t isnan(float32_t x)noexcept
	{
		return x != x;
	}

	constexpr float64_t isnan(float64_t x)noexcept
	{
		return x != x;
	}
}