module;

#include <cmath>

export module realmath.exp;

export import realmath.basic;

export namespace realmath
{
	constexpr float64_t exp_secure(float64_t x)noexcept;
	constexpr float32_t exp_secure(float32_t x)noexcept;
	float64_t exp_fast(float64_t x)noexcept;
	float32_t exp_fast(float32_t x)noexcept;

	constexpr float64_t exp(float64_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return exp_secure(x);
		}
		else
		{
			return exp_fast(x);
		}
	}

	constexpr float32_t exp(float32_t x)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return exp_secure(x);
		}
		else
		{
			return exp_fast(x);
		}
	}
}

import realmath.numeric_limits;
import realmath.numbers;
import realmath.isnan;
import realmath.pown;

namespace realmath
{
	constexpr float64_t exp_limited(const float64_t x_n)noexcept;
}

export namespace realmath
{
	constexpr float64_t exp_secure(float64_t x)noexcept
	{
		if(isnan(x))
		{
			return float64_t_nan;
		}
		if(x == -float64_t_inf)
		{
			return 0.0;
		}
		if(x < 0.0)
		{
			return 1.0 / exp_secure(-x);
		}
		if(1.0e9 <= x)
		{
			const float64_t a = exp_secure(x / 1.0e9);
			return pow(a, 1000000000UL);
		}
		if(8.0 <= x)
		{
			float64_t a = exp_secure(x / 8.0);
			a *= a;//a^2
			a *= a;//a^4
			return a * a;//a^8
		}
		const uint8_t q = static_cast<uint8_t>(x);
		x -= q;
		return exp_limited(x) * pow(e, q);
	}

	constexpr float32_t exp_secure(float32_t x)noexcept
	{
		return static_cast<float32_t>(exp_secure(static_cast<float64_t>(x)));
	}

	inline float64_t exp_fast(float64_t x)noexcept
	{
		__assume(x == x && x != -float64_t_inf);
		return std::exp(x);
	}

	inline float32_t exp_fast(float32_t x)noexcept
	{
		__assume(x == x && x != -float32_t_inf);
		return std::exp(x);
	}
}

namespace realmath
{
	//a0 = exp(x/2^n) - 1
	constexpr float64_t calc_a0(const float64_t x0)noexcept
	{
		constexpr float64_t c[] = {
			1.0 / (7 * 6 * 5 * 4 * 3 * 2),
			1.0 / (6 * 5 * 4 * 3 * 2),
			1.0 / (5 * 4 * 3 * 2),
			1.0 / (4 * 3 * 2),
			1.0 / (3 * 2),
			1.0 / (2),
			1.0,
		};
		float64_t y = c[0];
		for(size_t i = 1; i < sizeof(c)/sizeof(float64_t); ++i)
		{
			y = c[i] + y * x0;
		}
		return y * x0;
	}

	//an = exp(x) - 1
	template <size_t n>
	constexpr float64_t calc_an(float64_t a0)noexcept
	{
		for(size_t i = n; i; --i)
		{
			a0 = a0 * (a0 + 2.0);
		}
		return a0;
	}

	//-1.0 < x < 1.0
	constexpr float64_t exp_limited(float64_t x)noexcept
	{
		constexpr size_t n = 8;
		constexpr float64_t c = 1.0 / (1 << n);
		return calc_an<n>(calc_a0(x * c)) + 1.0;
	}
}