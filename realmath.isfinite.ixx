export module realmath.isfinite;

export import realmath.basic;
import realmath.numeric_limits;

export namespace realmath
{
	constexpr float32_t isfinite(float32_t x)noexcept
	{
		return x != float32_t_inf && x != -float32_t_inf;
	}

	constexpr float64_t isfinite(float64_t x)noexcept
	{
		return x != float64_t_inf && x != -float64_t_inf;
	}
}