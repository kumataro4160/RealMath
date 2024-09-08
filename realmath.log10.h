#ifndef KUMATARO_INCLUDE_REALMATH_LOG10_H
#define KUMATARO_INCLUDE_REALMATH_LOG10_H

#include <cmath>
#include "realmath.base.h"


namespace kuma
{
	constexpr float64_t log10_secure(float64_t x)noexcept;
	constexpr float32_t log10_secure(float32_t x)noexcept;
	float64_t log10_fast(float64_t x)noexcept;
	float32_t log10_fast(float32_t x)noexcept;

	constexpr float64_t log10(float64_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return log10_secure(x);
		}
		else
		{
			return log10_fast(x);
		}
	}

	constexpr float32_t log10(float32_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return log10_secure(x);
		}
		else
		{
			return log10_fast(x);
		}
	}
}


#include "realmath.numeric_limits.h"
#include "realmath.numbers.h"
#include "realmath.isnan.h"
#include "realmath.log.h"


namespace kuma
{
	constexpr float64_t log10_secure(float64_t x)noexcept
	{
		if(isnan(x))
		{
			return float64_t_nan;
		}
		return log_secure(x) * log10e;
	}

	constexpr float32_t log10_secure(float32_t x)noexcept
	{
		return static_cast<float32_t>(log10_secure(static_cast<float64_t>(x)));
	}

	inline float64_t log10_fast(float64_t x)noexcept
	{
		__assume(0.0 < x);
		return log_fast(x) * log10e;
	}

	inline float32_t log10_fast(float32_t x)noexcept
	{
		__assume(0.0f < x);
		return log_fast(x) * static_cast<float32_t>(log10e);
	}
}


#endif