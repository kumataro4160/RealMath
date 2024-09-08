#ifndef KUMATARO_INCLUDE_REALMATH_ACOS_H
#define KUMATARO_INCLUDE_REALMATH_ACOS_H

#include <cmath>
#include "realmath.base.h"


namespace kuma
{
	constexpr float64_t acos_secure(float64_t x)noexcept;
	constexpr float32_t acos_secure(float32_t x)noexcept;
	float64_t acos_fast(float64_t x)noexcept;
	float32_t acos_fast(float32_t x)noexcept;

	constexpr float64_t acos(float64_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return acos_secure(x);
		}
		else
		{
			return acos_fast(x);
		}
	}

	constexpr float32_t acos(float32_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return acos_secure(x);
		}
		else
		{
			return acos_fast(x);
		}
	}
}


#include "realmath.numeric_limits.h"
#include "realmath.numbers.h"
#include "realmath.isnan.h"
#include "realmath.iscloseto0.h"
#include "realmath.sqrt.h"
#include "realmath.arctan.h"


namespace kuma
{
	constexpr float64_t acos_secure(float64_t x)noexcept
	{
		if(isnan(x))
		{
			return float64_t_nan;
		}
		if(x > 1.0 || x < -1.0)
		{
			return float64_t_nan;
		}
		if(iscloseto0(x))
		{
			return pi / 2.0;
		}
		return arctan_secure(x, sqrt_secure(1.0 - x * x));
	}

	constexpr float32_t acos_secure(float32_t x)noexcept
	{
		return static_cast<float32_t>(acos_secure(static_cast<float64_t>(x)));
	}

	inline float64_t acos_fast(float64_t x)noexcept
	{
		__assume(-1.0 <= x && x <= 1.0);
		return std::acos(x);
	}

	inline float32_t acos_fast(float32_t x)noexcept
	{
		__assume(-1.0f <= x && x <= 1.0f);
		return std::acos(x);
	}
}


#endif