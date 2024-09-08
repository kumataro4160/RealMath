#ifndef KUMATARO_INCLUDE_REALMATH_POW_H
#define KUMATARO_INCLUDE_REALMATH_POW_H

#include <cmath>
#include "realmath.base.h"
#include "realmath.pown.h"


namespace kuma
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


#include "realmath.numeric_limits.h"
#include "realmath.isnan.h"
#include "realmath.exp.h"
#include "realmath.log.h"


namespace kuma
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


#endif