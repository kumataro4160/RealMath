#ifndef KUMATARO_INCLUDE_REALMATH_ROUND_H
#define KUMATARO_INCLUDE_REALMATH_ROUND_H

#include "realmath.base.h"


namespace kuma
{
	constexpr whole_t round(float32_t x)noexcept
	{
		if(x >= 0.0f)
		{
			return static_cast<whole_t>(x + 0.5f);
		}
		else
		{
			return static_cast<whole_t>(x - 0.5f);
		}
	}

	constexpr whole_t round(float64_t x)noexcept
	{
		if(x >= 0.0f)
		{
			return static_cast<whole_t>(x + 0.5);
		}
		else
		{
			return static_cast<whole_t>(x - 0.5);
		}
	}
}


#endif