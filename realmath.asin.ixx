module;

#include <cmath>

export module realmath.asin;

export import realmath.basic;

export namespace kuma
{
	constexpr float64_t asin_secure(float64_t x)noexcept;
	constexpr float32_t asin_secure(float32_t x)noexcept;
	float64_t asin_fast(float64_t x)noexcept;
	float32_t asin_fast(float32_t x)noexcept;

	constexpr float64_t asin(float64_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return asin_secure(x);
		}
		else
		{
			return asin_fast(x);
		}
	}

	constexpr float32_t asin(float32_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return asin_secure(x);
		}
		else
		{
			return asin_fast(x);
		}
	}
}

import realmath.numeric_limits;
import realmath.isnan;
import realmath.iscloseto0;
import realmath.sqrt;
import realmath.arctan;

export namespace kuma
{
	constexpr float64_t asin_secure(float64_t x)noexcept
	{
		if(isnan(x))
		{
			return float64_t_nan;
		}
		if(iscloseto0(x))
		{
			return 0.0;
		}
		if(x < -1.0 || 1.0 < x)
		{
			return float64_t_nan;
		}
		else
		{
			return arctan_secure(sqrt_secure(1.0 - x * x), x);
		}
	}

	constexpr float32_t asin_secure(float32_t x)noexcept
	{
		return static_cast<float32_t>(asin_secure(static_cast<float64_t>(x)));
	}

	inline float64_t asin_fast(float64_t x)noexcept
	{
		__assume(-1.0 <= x && x <= 1.0);
		return std::asin(x);
	}

	inline float32_t asin_fast(float32_t x)noexcept
	{
		__assume(-1.0 <= x && x <= 1.0);
		return std::asin(x);
	}
}