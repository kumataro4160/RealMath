#ifndef KUMATARO_INCLUDE_REALMATH_ATANH_H
#define KUMATARO_INCLUDE_REALMATH_ATANH_H

#include <cmath>
#include "realmath.base.h"


namespace kuma
{
	constexpr float64_t atanh_secure(float64_t x)noexcept;
	constexpr float32_t atanh_secure(float32_t x)noexcept;
	float64_t atanh_fast(float64_t x)noexcept;
	float32_t atanh_fast(float32_t x)noexcept;

	constexpr float64_t atanh(float64_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return atanh_secure(x);
		}
		else
		{
			return atanh_fast(x);
		}
	}

	constexpr float32_t atanh(float32_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return atanh_secure(x);
		}
		else
		{
			return atanh_fast(x);
		}
	}
}


#include "realmath.numeric_limits.h"
#include "realmath.isnan.h"
#include "realmath.log.h"


namespace kuma
{
	constexpr float64_t atanh_secure(float64_t x)noexcept
	{
		if(isnan(x))
		{
			return float64_t_nan;
		}
		if(x < -1.0 || 1.0 < x)
		{
			return float64_t_nan;
		}
		if(x == -1.0)
		{
			return -float64_t_inf;
		}
		if(x == 1.0)
		{
			return float64_t_inf;
		}
		return 0.5 * log_secure((1.0 + x) / (1.0 - x)); // -1.0 < x < 1.0
	}

	constexpr float32_t atanh_secure(float32_t x)noexcept
	{
		return static_cast<float32_t>(atanh_secure(static_cast<float64_t>(x)));
	}

	inline float64_t atanh_fast(float64_t x)noexcept
	{
		__assume(-1.0 <= x && x <= 1.0);
		if(x == 1.0)
		{
			return float64_t_inf;
		}
		return 0.5 * log_fast((1.0 + x) / (1.0 - x));
	}

	inline float32_t atanh_fast(float32_t x)noexcept
	{
		__assume(-1.0f <= x && x <= 1.0f);
		if(x == 1.0f)
		{
			return float32_t_inf;
		}
		return 0.5f * log_fast((1.0f + x) / (1.0f - x));
	}
}


#endif