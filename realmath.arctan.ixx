module;

#include <cmath>

export module realmath.arctan;

export import realmath.basic;

export namespace realmath
{
	constexpr float64_t arctan_secure(float64_t x, float64_t y)noexcept;
	constexpr float32_t arctan_secure(float32_t x, float32_t y)noexcept;
	float64_t arctan_fast(float64_t x, float64_t y)noexcept;
	float32_t arctan_fast(float32_t x, float32_t y)noexcept;

	constexpr float64_t arctan(float64_t x, float64_t y)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return arctan_secure(x, y);
		}
		else
		{
			return arctan_fast(x, y);
		}
	}

	constexpr float32_t arctan(float32_t x, float32_t y)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return arctan_secure(x, y);
		}
		else
		{
			return arctan_fast(x, y);
		}
	}
}

import realmath.numeric_limits;
import realmath.numbers;
import realmath.isnan;
import realmath.iscloseto0;
import realmath.atan;

export namespace realmath
{
	constexpr float64_t arctan_secure(float64_t x, float64_t y)noexcept
	{
		if(isnan(x) || isnan(y))
		{
			return float64_t_nan;
		}
		if(iscloseto0(x))
		{
			if(iscloseto0(y))
			{
				if(y >= 0.0)
				{
					if(x >= 0.0)	// x = +0 && y = +0
					{
						return 0.0;
					}
					else			// x = -0 && y = +0
					{
						return pi;
					}
				}
				else
				{
					if(x >= 0.0)	// x = +0 && y = -0
					{
						return -0.0;
					}
					else			// x = -0 && y = -0
					{
						return -pi;
					}
				}
			}
			else if(y >= 0.0)		// x = 0 && y > 0
			{
				return pi / 2.0;
			}
			else					// x = 0 && y < 0
			{
				return -pi / 2.0;
			}
		}
		else if(x >= 0.0)			// x > 0
		{
			return atan_secure(y / x);
		}
		else if(y >= 0.0)			// x < 0 && y > 0
		{
			return atan_secure(y / x) + pi;
		}
		else						// x < 0 && y < 0
		{
			return atan_secure(y / x) - pi;
		}
	}

	constexpr float32_t arctan_secure(float32_t x, float32_t y)noexcept
	{
		return static_cast<float32_t>(arctan_secure(static_cast<float64_t>(x), static_cast<float64_t>(y)));
	}

	inline float64_t arctan_fast(float64_t x, float64_t y)noexcept
	{
		__assume(x == x);
		return std::atan2(y, x);
	}

	inline float32_t arctan_fast(float32_t x, float32_t y)noexcept
	{
		__assume(x == x);
		return std::atan2(y, x);
	}
}