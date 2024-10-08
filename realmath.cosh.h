﻿#ifndef KUMATARO_INCLUDE_REALMATH_COSH_H
#define KUMATARO_INCLUDE_REALMATH_COSH_H

#include <cmath>
#include "realmath.base.h"


namespace kuma
{
	constexpr float64_t cosh_secure(float64_t x)noexcept;
	constexpr float32_t cosh_secure(float32_t x)noexcept;
	float64_t cosh_fast(float64_t x)noexcept;
	float32_t cosh_fast(float32_t x)noexcept;

	constexpr float64_t cosh(float64_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return cosh_secure(x);
		}
		else
		{
			return cosh_fast(x);
		}
	}

	constexpr float32_t cosh(float32_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return cosh_secure(x);
		}
		else
		{
			return cosh_fast(x);
		}
	}
}


#include "realmath.numeric_limits.h"
#include "realmath.isnan.h"
#include "realmath.exp.h"


namespace kuma
{
	constexpr float64_t cosh_secure(float64_t x)noexcept
	{
		if(isnan(x))
		{
			return float64_t_nan;
		}
		return (exp_secure(x) + exp_secure(-x)) * 0.5;
	}

	constexpr float32_t cosh_secure(float32_t x)noexcept
	{
		return static_cast<float32_t>(cosh_secure(static_cast<float64_t>(x)));
	}

	inline float64_t cosh_fast(float64_t x)noexcept
	{
		__assume(x != -float64_t_inf && x != float64_t_inf);
		return std::cosh(x);
	}

	inline float32_t cosh_fast(float32_t x)noexcept
	{
		__assume(x != -float32_t_inf && x != float32_t_inf);
		return std::cosh(x);
	}
}


#endif