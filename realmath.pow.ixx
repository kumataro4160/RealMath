module;

#include <cmath>

export module realmath.pow;

export import realmath.basic;
export import realmath.pown;

export namespace realmath
{
	constexpr float64_t pow_secure(float64_t x, float64_t y)noexcept;
	constexpr float32_t pow_secure(float32_t x, float32_t y)noexcept;
	float64_t pow_fast(float64_t x, float64_t y)noexcept;
	float32_t pow_fast(float32_t x, float32_t y)noexcept;

	constexpr float64_t pow(float64_t x, float64_t y)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return pow_secure(x, y);
		}
		else
		{
			return pow_fast(x, y);
		}
	}

	constexpr float32_t pow(float32_t x, float32_t y)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return pow_secure(x, y);
		}
		else
		{
			return pow_fast(x, y);
		}
	}
}

import realmath.numeric_limits;
import realmath.isnan;
import realmath.exp;
import realmath.log;

export namespace realmath
{
	constexpr float64_t pow_secure(float64_t x, float64_t y)noexcept
	{
		if(isnan(x) || isnan(y))
		{
			return float64_t_nan;
		}
		return exp_secure(log_secure(x) * y);
	}

	constexpr float32_t pow_secure(float32_t x, float32_t y)noexcept
	{
		return static_cast<float32_t>(pow_secure(static_cast<float64_t>(x), static_cast<float64_t>(y)));
	}

	inline float64_t pow_fast(float64_t x, float64_t y)noexcept
	{
		__assume(x == x && y == y);
		return exp_fast(log_fast(x) * y);
	}

	inline float32_t pow_fast(float32_t x, float32_t y)noexcept
	{
		__assume(x == x && y == y);
		return exp_fast(log_fast(x) * y);
	}
}