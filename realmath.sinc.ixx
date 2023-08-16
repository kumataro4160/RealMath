module;

#include <cmath>

export module realmath.sinc;

export import realmath.basic;

export namespace kuma
{
	constexpr float64_t sinc_secure(float64_t x)noexcept;
	constexpr float32_t sinc_secure(float32_t x)noexcept;
	float64_t sinc_fast(float64_t x)noexcept;
	float32_t sinc_fast(float32_t x)noexcept;

	constexpr float64_t sinc(float64_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return sinc_secure(x);
		}
		else
		{
			return sinc_fast(x);
		}
	}

	constexpr float32_t sinc(float32_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return sinc_secure(x);
		}
		else
		{
			return sinc_fast(x);
		}
	}
}

import realmath.numeric_limits;
import realmath.iscloseto0;
import realmath.isnan;
import realmath.sin;

export namespace kuma
{
	constexpr float64_t sinc_secure(float64_t x)noexcept
	{
		if(isnan(x))
		{
			return float64_t_nan;
		}
		if(iscloseto0(x))
		{
			return 1.0;
		}
		return sin_secure(x) / x;
	}

	constexpr float32_t sinc_secure(float32_t x)noexcept
	{
		return static_cast<float32_t>(sinc_secure(static_cast<float64_t>(x)));
	}

	inline float64_t sinc_fast(float64_t x)noexcept
	{
		__assume(x == x);
		if(iscloseto0(x))
		{
			return 1.0;
		}
		return sin_fast(x) / x;
	}

	inline float32_t sinc_fast(float32_t x)noexcept
	{
		__assume(x == x);
		if(iscloseto0(x))
		{
			return 1.0f;
		}
		return sin_fast(x) / x;
	}
}