﻿module;

#include <cmath>

export module realmath.cycle;

export import realmath.basic;

export namespace kuma
{
	constexpr float64_t cycle_secure(float64_t x, float64_t length)noexcept;
	constexpr float32_t cycle_secure(float32_t x, float32_t length)noexcept;
	float64_t cycle_fast(float64_t x, float64_t length)noexcept;
	float32_t cycle_fast(float32_t x, float32_t length)noexcept;

	constexpr float64_t cycle(float64_t x, float64_t length)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return cycle_secure(x, length);
		}
		else
		{
			return cycle_fast(x, length);
		}
	}

	constexpr float32_t cycle(float32_t x, float32_t length)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return cycle_secure(x, length);
		}
		else
		{
			return cycle_fast(x, length);
		}
	}
}

import realmath.numeric_limits;
import realmath.isnan;
import realmath.floor;

export namespace kuma
{
	constexpr float64_t cycle_secure(float64_t x, float64_t length)noexcept
	{
		if(isnan(x))
		{
			return float64_t_nan;
		}
		if(length <= 0.0)
		{
			return float64_t_nan;
		}
		return x - floor(x / length) * length;
	}

	constexpr float32_t cycle_secure(float32_t x, float32_t length)noexcept
	{
		return static_cast<float32_t>(cycle_secure(static_cast<float64_t>(x), static_cast<float64_t>(length)));
	}

	inline float64_t cycle_fast(float64_t x, float64_t length)noexcept
	{
		__assume(x == x && length > 0.0);
		return x - floor(x / length) * length;
	}

	inline float32_t cycle_fast(float32_t x, float32_t length)noexcept
	{
		__assume(x == x && length > 0.0);
		return x - floor(x / length) * length;
	}
}