module;

#include <cmath>

export module realmath.log;

export import realmath.basic;

export namespace realmath
{
	constexpr float64_t log_secure(float64_t x)noexcept;
	constexpr float32_t log_secure(float32_t x)noexcept;
	float64_t log_fast(float64_t x)noexcept;
	float32_t log_fast(float32_t x)noexcept;

	constexpr float64_t log(float64_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return log_secure(x);
		}
		else
		{
			return log_fast(x);
		}
	}

	constexpr float32_t log(float32_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return log_secure(x);
		}
		else
		{
			return log_fast(x);
		}
	}
}

import realmath.numeric_limits;
import realmath.numbers;
import realmath.isnan;

namespace realmath
{
	constexpr float64_t log1p_limited(float64_t x)noexcept;
}

export namespace realmath
{
	constexpr float64_t log_secure(float64_t x)noexcept
	{
		constexpr float64_t sqrt_e = 1.6487212707001281468486507878142;
		constexpr float64_t qdrt_e = 1.2840254166877414840734205680624;
		constexpr float64_t sqrt_ie = 1.0 / sqrt_e;
		constexpr float64_t qdrt_ie = 1.0 / qdrt_e;

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
			return -float64_t_inf;
		}
		if(x == float64_t_inf)
		{
			return float64_t_inf;
		}
		constexpr float64_t e_4 = e * e * e * e;
		constexpr float64_t e_i4 = 1.0 / e_4;
		if(x <= e_i4)
		{
			return log_secure(x * e_4) - 4.0;
		}
		if(e_4 <= x)
		{
			return log_secure(x * e_i4) + 4.0;
		}
		if(x <= inv_e)
		{
			return log_secure(x * e) - 1.0;
		}
		if(e <= x)
		{
			return log_secure(x * inv_e) + 1.0;
		}
		if(x <= sqrt_ie)
		{
			return log_secure(x * sqrt_e) - 0.5;
		}
		if(sqrt_e <= x)
		{
			return log_secure(x * sqrt_ie) + 0.5;
		}
		if(x <= qdrt_ie)
		{
			return log_secure(x * qdrt_e) - 0.25;
		}
		if(qdrt_e <= x)
		{
			return log_secure(x * qdrt_ie) + 0.25;
		}
		return log1p_limited(x - 1.0);// sqrt(1.0/e) < x < sqrt(e)
	}

	constexpr float32_t log_secure(float32_t x)noexcept
	{
		return static_cast<float32_t>(log_secure(static_cast<float64_t>(x)));
	}

	inline float64_t log_fast(float64_t x)noexcept
	{
		__assume(0.0 <= x);
		return std::log(x);
	}

	inline float32_t log_fast(float32_t x)noexcept
	{
		__assume(0.0f <= x);
		return std::log(x);
	}
}

namespace realmath
{
	// (1.0/e)^(1.0/4.0) - 1.0 < x < e^(1.0/4.0) - 1.0
	constexpr float64_t log1p_limited(float64_t x)noexcept
	{
		float64_t x_n = x;
		float64_t ret = x_n;
		x_n *= x;
		ret -= x_n / 2.0;
		x_n *= x;
		ret += x_n / 3.0;
		x_n *= x;
		ret -= x_n / 4.0;
		x_n *= x;
		ret += x_n / 5.0;
		x_n *= x;
		ret -= x_n / 6.0;
		x_n *= x;
		ret += x_n / 7.0;
		x_n *= x;
		ret -= x_n / 8.0;
		x_n *= x;
		ret += x_n / 9.0;
		x_n *= x;
		ret -= x_n / 10.0;
		x_n *= x;
		ret += x_n / 11.0;
		x_n *= x;
		ret -= x_n / 12.0;
		x_n *= x;
		ret += x_n / 13.0;
		x_n *= x;
		ret -= x_n / 14.0;
		x_n *= x;
		ret += x_n / 15.0;
		x_n *= x;
		ret -= x_n / 16.0;
		x_n *= x;
		ret += x_n / 17.0;
		x_n *= x;
		ret -= x_n / 18.0;
		x_n *= x;
		ret += x_n / 19.0;
		x_n *= x;
		ret -= x_n / 20.0;
		x_n *= x;
		ret += x_n / 21.0;
		x_n *= x;
		ret -= x_n / 22.0;
		x_n *= x;
		ret += x_n / 23.0;
		x_n *= x;
		ret -= x_n / 24.0;
		x_n *= x;
		ret += x_n / 25.0;
		x_n *= x;
		ret -= x_n / 26.0;
		return ret;
	}
}