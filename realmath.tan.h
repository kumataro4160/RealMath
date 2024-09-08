#ifndef KUMATARO_INCLUDE_REALMATH_TAN_H
#define KUMATARO_INCLUDE_REALMATH_TAN_H

#include <cmath>
#include "realmath.base.h"


namespace kuma
{
	constexpr float64_t tan_secure(float64_t x)noexcept;
	constexpr float32_t tan_secure(float32_t x)noexcept;
	float64_t tan_fast(float64_t x)noexcept;
	float32_t tan_fast(float32_t x)noexcept;

	constexpr float64_t tan(float64_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return tan_secure(x);
		}
		else
		{
			return tan_fast(x);
		}
	}

	constexpr float32_t tan(float32_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return tan_secure(x);
		}
		else
		{
			return tan_fast(x);
		}
	}
}


#include "realmath.numeric_limits.h"
#include "realmath.isnan.h"
#include "realmath.iscloseto0.h"
#include "realmath.sin.h"
#include "realmath.cos.h"


namespace kuma
{
	constexpr float64_t tan_secure(float64_t x)noexcept
	{
		if(isnan(x))
		{
			return float64_t_nan;
		}
		const float64_t cosX = cos_secure(x);
		const float64_t sinX = sin_secure(x);
		if(iscloseto0(cosX))
		{
			return sinX * cosX * float64_t_inf;
		}
		else
		{
			return sinX / cosX;
		}
	}

	constexpr float32_t tan_secure(float32_t x)noexcept
	{
		return static_cast<float32_t>(tan_secure(static_cast<float64_t>(x)));
	}

	inline float64_t tan_fast(float64_t x)noexcept
	{
		__assume(x == x);
		return std::tan(x);
	}

	inline float32_t tan_fast(float32_t x)noexcept
	{
		__assume(x == x);
		return std::tan(x);
	}
}


#endif