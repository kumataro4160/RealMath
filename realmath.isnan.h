#ifndef KUMATARO_INCLUDE_REALMATH_ISNAN_H
#define KUMATARO_INCLUDE_REALMATH_ISNAN_H

#include "realmath.base.h"


namespace kuma
{
	constexpr float32_t isnan(float32_t x)noexcept
	{
		return x != x;
	}

	constexpr float64_t isnan(float64_t x)noexcept
	{
		return x != x;
	}
}


#endif