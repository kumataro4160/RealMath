#ifndef KUMATARO_INCLUDE_REALMATH_SQRT_H
#define KUMATARO_INCLUDE_REALMATH_SQRT_H

#include <cmath>

#include "realmath.base.h"


namespace kuma
{
	constexpr float64_t sqrt_secure(float64_t x)noexcept;
	constexpr float32_t sqrt_secure(float32_t x)noexcept;
	float64_t sqrt_fast(float64_t x)noexcept;
	float32_t sqrt_fast(float32_t x)noexcept;

	constexpr float64_t sqrt(float64_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return sqrt_secure(x);
		}
		else
		{
			return sqrt_fast(x);
		}
	}

	constexpr float32_t sqrt(float32_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return sqrt_secure(x);
		}
		else
		{
			return sqrt_fast(x);
		}
	}
}


#include "realmath.numeric_limits.h"
#include "realmath.isnan.h"


namespace kuma
{
	constexpr float64_t sqrt_limited(float64_t x)noexcept;
}

namespace kuma
{
	constexpr float64_t sqrt_secure(float64_t x)noexcept
	{
		if(isnan(x))
		{
			return float64_t_nan;
		}
		if(x < 0.0)
		{
			return float64_t_nan;
		}
		if(x <= float64_t_min)
		{
			return 0.0;
		}
		if(x == float64_t_inf)
		{
			return float64_t_inf;
		}
		if(0.25 < x)
		{
			if(x < 2.0)
			{
				return sqrt_limited(x);// 0.25 < x < 2.0
			}
			return sqrt_secure(x * 0.25) * 2.0;
		}
		return sqrt_secure(x * 4.0) * 0.5;
	}

	constexpr float32_t sqrt_secure(float32_t x)noexcept
	{
		return static_cast<float32_t>(sqrt_secure(static_cast<float64_t>(x)));
	}

	inline float64_t sqrt_fast(float64_t x)noexcept
	{
		__assume(0.0 <= x);
		return std::sqrt(x);
	}

	inline float32_t sqrt_fast(float32_t x)noexcept
	{
		__assume(0.0f <= x);
		return std::sqrt(x);
	}
}

namespace kuma
{
	// 0.25 < x < 2.0
	constexpr float64_t sqrt_limited(float64_t x)noexcept
	{
		float64_t a_n = 1.0;
		for(uint64_t n = 6; n; --n)
		{
			a_n = ((x / a_n) + a_n) * 0.5;
		}
		return a_n;
	}
}


#endif