#ifndef KUMATARO_INCLUDE_REALMATH_HANN_H
#define KUMATARO_INCLUDE_REALMATH_HANN_H

#include <cmath>
#include "realmath.base.h"


namespace kuma
{
	constexpr float64_t hann_secure(float64_t x)noexcept;
	constexpr float32_t hann_secure(float32_t x)noexcept;
	float64_t hann_fast(float64_t x)noexcept;
	float32_t hann_fast(float32_t x)noexcept;

	constexpr float64_t hann(float64_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return hann_secure(x);
		}
		else
		{
			return hann_fast(x);
		}
	}

	constexpr float32_t hann(float32_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return hann_secure(x);
		}
		else
		{
			return hann_fast(x);
		}
	}
}


#include "realmath.numeric_limits.h"
#include "realmath.numbers.h"
#include "realmath.isnan.h"
#include "realmath.cos.h"


namespace kuma
{
	constexpr float64_t hann_secure(float64_t x)noexcept
	{
		if(isnan(x))
		{
			return float64_t_nan;
		}
		if(x <= -pi && pi <= x)
		{
			return 0.0;
		}
		return 0.5 + 0.5 * cos_secure(x);
	}

	constexpr float32_t hann_secure(float32_t x)noexcept
	{
		return static_cast<float32_t>(hann_secure(static_cast<float64_t>(x)));
	}

	inline float64_t hann_fast(float64_t x)noexcept
	{
		__assume(-pi <= x && x <= pi);
		return 0.5 + 0.5 * cos_fast(x);
	}

	inline float32_t hann_fast(float32_t x)noexcept
	{
		__assume(-pi <= x && x <= pi);
		return 0.5f + 0.5f * cos_fast(x);
	}
}


#endif