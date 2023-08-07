module;

#include <cmath>

export module realmath.sin;

export import realmath.basic;

export namespace realmath
{
	constexpr float64_t sin_secure(float64_t x)noexcept;
	constexpr float32_t sin_secure(float32_t x)noexcept;
	float64_t sin_fast(float64_t x)noexcept;
	float32_t sin_fast(float32_t x)noexcept;

	constexpr float64_t sin(float64_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return sin_secure(x);
		}
		else
		{
			return sin_fast(x);
		}
	}

	constexpr float32_t sin(float32_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return sin_secure(x);
		}
		else
		{
			return sin_fast(x);
		}
	}
}

import realmath.numeric_limits;
import realmath.numbers;
import realmath.isnan;
import realmath.cos;

export namespace realmath
{
	constexpr float64_t sin_secure(float64_t x)noexcept
	{
		constexpr float64_t halfPi = pi * 0.5;
		if(isnan(x))
		{
			return float64_t_nan;
		}
		return cos_secure(x - halfPi);
	}

	constexpr float32_t sin_secure(float32_t x)noexcept
	{
		return static_cast<float32_t>(sin_secure(static_cast<float64_t>(x)));
	}

	inline float64_t sin_fast(float64_t x)noexcept
	{
		__assume(x == x);
		return std::sin(x);
	}

	inline float32_t sin_fast(float32_t x)noexcept
	{
		__assume(x == x);
		return std::sin(x);
	}
}