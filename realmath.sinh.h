﻿#ifndef KUMATARO_INCLUDE_REALMATH_SINH_H
#define KUMATARO_INCLUDE_REALMATH_SINH_H

#include <cmath>
#include "realmath.base.h"


namespace kuma
{
	constexpr float64_t sinh_secure(float64_t x)noexcept;
	constexpr float32_t sinh_secure(float32_t x)noexcept;
	float64_t sinh_fast(float64_t x)noexcept;
	float32_t sinh_fast(float32_t x)noexcept;

	constexpr float64_t sinh(float64_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return sinh_secure(x);
		}
		else
		{
			return sinh_fast(x);
		}
	}

	constexpr float32_t sinh(float32_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return sinh_secure(x);
		}
		else
		{
			return sinh_fast(x);
		}
	}
}


#include "realmath.numeric_limits.h"
#include "realmath.isnan.h"
#include "realmath.exp.h"


namespace kuma
{
	constexpr float64_t sinh_secure(float64_t x)noexcept
	{
		if(isnan(x))
		{
			return float64_t_nan;
		}
		return (exp_secure(x) - exp_secure(-x)) * 0.5;
	}

	constexpr float32_t sinh_secure(float32_t x)noexcept
	{
		return static_cast<float32_t>(sinh_secure(static_cast<float64_t>(x)));
	}

	inline float64_t sinh_fast(float64_t x)noexcept
	{
		__assume(x != -float64_t_inf && x != float64_t_inf);
		return std::sinh(x);
	}

	inline float32_t sinh_fast(float32_t x)noexcept
	{
		__assume(x != -float32_t_inf && x != float32_t_inf);
		return std::sinh(x);
	}
}


#endif