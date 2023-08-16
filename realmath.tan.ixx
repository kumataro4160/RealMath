module;

#include <cmath>

export module realmath.tan;

export import realmath.basic;

export namespace kuma
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

import realmath.numeric_limits;
import realmath.isnan;
import realmath.iscloseto0;
import realmath.sin;
import realmath.cos;

export namespace kuma
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