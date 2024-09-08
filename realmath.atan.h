#ifndef KUMATARO_INCLUDE_REALMATH_ATAN_H
#define KUMATARO_INCLUDE_REALMATH_ATAN_H

#include <cmath>
#include "realmath.base.h"


namespace kuma
{
	constexpr float64_t atan_secure(float64_t x)noexcept;
	constexpr float32_t atan_secure(float32_t x)noexcept;
	float64_t atan_fast(float64_t x)noexcept;
	float32_t atan_fast(float32_t x)noexcept;

	constexpr float64_t atan(float64_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return atan_secure(x);
		}
		else
		{
			return atan_fast(x);
		}
	}

	constexpr float32_t atan(float32_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return atan_secure(x);
		}
		else
		{
			return atan_fast(x);
		}
	}
}


#include "realmath.numeric_limits.h"
#include "realmath.numbers.h"
#include "realmath.isnan.h"
#include "realmath.sqrt.h"


namespace kuma::impl
{
	constexpr float64_t atan_limited(float64_t x)noexcept;
}

namespace kuma
{
	using namespace impl;

	constexpr float64_t atan_secure(float64_t x)noexcept
	{
		constexpr float64_t sqrt2 = 1.4142135623730950488016887242097;

		if(isnan(x))
		{
			return float64_t_nan;
		}
		if(x < 0.0)
		{
			return -atan_secure(-x);
		}
		if(x > sqrt2 + 1.0)
		{
			return pi / 2.0 - atan(1.0 / x);
		}
		if(x > sqrt2 - 1.0)
		{
			return pi / 4.0 + atan((x - 1.0) / (x + 1.0));
		}
		return atan_limited(x);// 0.0 < x <= sqrt(2.0) - 1.0
	}

	constexpr float32_t atan_secure(float32_t x)noexcept
	{
		return static_cast<float32_t>(atan_secure(static_cast<float64_t>(x)));
	}

	inline float64_t atan_fast(float64_t x)noexcept
	{
		__assume(x == x);
		return std::atan(x);
	}

	inline float32_t atan_fast(float32_t x)noexcept
	{
		__assume(x == x);
		return std::atan(x);
	}
}

namespace kuma::impl
{
	// -sqrt(2.0) + 1.0 <= x <= sqrt(2.0) - 1.0
	constexpr float64_t atan_limited(float64_t x)noexcept
	{
		const float64_t x_2 = x * x;
		float64_t ret = x;
		x *= x_2;
		ret -= x / 3.0;
		x *= x_2;
		ret += x / 5.0;
		x *= x_2;
		ret -= x / 7.0;
		x *= x_2;
		ret += x / 9.0;
		x *= x_2;
		ret -= x / 11.0;
		x *= x_2;
		ret += x / 13.0;
		x *= x_2;
		ret -= x / 15.0;
		x *= x_2;
		ret += x / 17.0;
		x *= x_2;
		ret -= x / 19.0;
		x *= x_2;
		ret += x / 21.0;
		x *= x_2;
		ret -= x / 23.0;
		x *= x_2;
		ret += x / 25.0;
		x *= x_2;
		ret -= x / 27.0;
		x *= x_2;
		ret += x / 29.0;
		x *= x_2;
		ret -= x / 31.0;
		x *= x_2;
		ret += x / 33.0;
		return ret;
	}
}


#endif