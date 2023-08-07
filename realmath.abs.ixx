module;

#include <cmath>

export module realmath.abs;

export import realmath.basic;

export namespace realmath
{
	constexpr float64_t abs_secure(float64_t x)noexcept;
	constexpr float32_t abs_secure(float32_t x)noexcept;
	float64_t abs_fast(float64_t x)noexcept;
	float32_t abs_fast(float32_t x)noexcept;

	constexpr float64_t abs(float64_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return abs_secure(x);
		}
		else
		{
			return abs_fast(x);
		}
	}

	constexpr float32_t abs(float32_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return abs_secure(x);
		}
		else
		{
			return abs_fast(x);
		}
	}
}

import realmath.numeric_limits;
import realmath.isnan;

export namespace realmath
{
	constexpr float64_t abs_secure(float64_t x)noexcept
	{
		if(isnan(x))
		{
			return float64_t_nan;
		}
		return x >= 0.0 ? x : -x;
	}

	constexpr float32_t abs_secure(float32_t x)noexcept
	{
		return static_cast<float32_t>(abs_secure(static_cast<float64_t>(x)));
	}

	inline float64_t abs_fast(float64_t x)noexcept
	{
		__assume(x == x);
		return x >= 0.0 ? x : -x;
	}

	inline float32_t abs_fast(float32_t x)noexcept
	{
		__assume(x == x);
		return x >= 0.0f ? x : -x;
	}
}