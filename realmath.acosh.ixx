﻿module;

#include <cmath>

export module realmath.acosh;

export import realmath.basic;

export namespace kuma
{
	constexpr float64_t acosh_secure(float64_t x)noexcept;
	constexpr float32_t acosh_secure(float32_t x)noexcept;
	float64_t acosh_fast(float64_t x)noexcept;
	float32_t acosh_fast(float32_t x)noexcept;

	constexpr float64_t acosh(float64_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return acosh_secure(x);
		}
		else
		{
			return acosh_fast(x);
		}
	}

	constexpr float32_t acosh(float32_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return acosh_secure(x);
		}
		else
		{
			return acosh_fast(x);
		}
	}
}

import realmath.numeric_limits;
import realmath.isnan;
import realmath.sqrt;
import realmath.log;

export namespace kuma
{
	constexpr float64_t acosh_secure(float64_t x)noexcept
	{
		if(isnan(x))
		{
			return float64_t_nan;
		}
		return log_secure(x + sqrt_secure(x * x - 1.0));
	}

	constexpr float32_t acosh_secure(float32_t x)noexcept
	{
		return static_cast<float32_t>(acosh_secure(static_cast<float64_t>(x)));
	}

	inline float64_t acosh_fast(float64_t x)noexcept
	{
		__assume(1.0 <= x);
		const float64_t a = x * x - 1.0;
		__assume(0.0 <= a);
		return log_fast(x + sqrt_fast(a));
	}

	inline float32_t acosh_fast(float32_t x)noexcept
	{
		__assume(1.0f <= x);
		const float32_t a = x * x - 1.0f;
		__assume(0.0f <= a);
		return log_fast(x + sqrt_fast(a));
	}
}