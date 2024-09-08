#ifndef KUMATARO_INCLUDE_REALMATH_SIN_H
#define KUMATARO_INCLUDE_REALMATH_SIN_H

#include <cmath>
#include "realmath.base.h"


namespace kuma
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


#include "realmath.numeric_limits.h"
#include "realmath.numbers.h"
#include "realmath.isnan.h"
#include "realmath.cos.h"


namespace kuma
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


#endif