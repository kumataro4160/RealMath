module;

#include <cmath>

export module realmath.hypot;

export import realmath.basic;

export namespace kuma
{
	constexpr float64_t hypot_secure(float64_t x, float64_t y)noexcept;
	constexpr float32_t hypot_secure(float32_t x, float32_t y)noexcept;
	float64_t hypot_fast(float64_t x, float64_t y)noexcept;
	float32_t hypot_fast(float32_t x, float32_t y)noexcept;

	constexpr float64_t hypot(float64_t x, float64_t y)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return hypot_secure(x, y);
		}
		else
		{
			return hypot_fast(x, y);
		}
	}

	constexpr float32_t hypot(float32_t x, float32_t y)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return hypot_secure(x, y);
		}
		else
		{
			return hypot_fast(x, y);
		}
	}
}

import realmath.numeric_limits;
import realmath.isnan;
import realmath.sqrt;

export namespace kuma
{
	constexpr float64_t hypot_secure(float64_t x, float64_t y)noexcept
	{
		if(isnan(x) || isnan(y))
		{
			return float64_t_nan;
		}
		return sqrt_secure(x * x + y * y);
	}

	constexpr float32_t hypot_secure(float32_t x, float32_t y)noexcept
	{
		return static_cast<float32_t>(hypot_secure(static_cast<float64_t>(x), static_cast<float64_t>(y)));
	}

	inline float64_t hypot_fast(float64_t x, float64_t y)noexcept
	{
		__assume(x == x && y == y);
		return sqrt_fast(x * x + y * y);
	}

	inline float32_t hypot_fast(float32_t x, float32_t y)noexcept
	{
		__assume(x == x && y == y);
		return sqrt_fast(x * x + y * y);
	}
}