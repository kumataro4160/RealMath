﻿module;

#include <cmath>

export module realmath.tanh;

export import realmath.basic;

export namespace realmath
{
	constexpr float64_t tanh_secure(float64_t x)noexcept;
	constexpr float32_t tanh_secure(float32_t x)noexcept;
	float64_t tanh_fast(float64_t x)noexcept;
	float32_t tanh_fast(float32_t x)noexcept;

	constexpr float64_t tanh(float64_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return tanh_secure(x);
		}
		else
		{
			return tanh_fast(x);
		}
	}

	constexpr float32_t tanh(float32_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return tanh_secure(x);
		}
		else
		{
			return tanh_fast(x);
		}
	}
}

import realmath.numeric_limits;
import realmath.isnan;
import realmath.exp;

export namespace realmath
{
	constexpr float64_t tanh_secure(float64_t x)noexcept
	{
		if(isnan(x))
		{
			return float64_t_nan;
		}
		const float64_t a = exp_secure(x);
		const float64_t b = exp_secure(-x);
		return (a - b) / (a + b);
	}

	constexpr float32_t tanh_secure(float32_t x)noexcept
	{
		return static_cast<float32_t>(tanh_secure(static_cast<float64_t>(x)));
	}

	inline float64_t tanh_fast(float64_t x)noexcept
	{
		__assume(x != -float64_t_inf && x != float64_t_inf);
		return std::tanh(x);
	}

	inline float32_t tanh_fast(float32_t x)noexcept
	{
		__assume(x != -float32_t_inf && x != float32_t_inf);
		return std::tanh(x);
	}
}