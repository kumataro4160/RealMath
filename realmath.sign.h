#ifndef KUMATARO_INCLUDE_REALMATH_SIGN_H
#define KUMATARO_INCLUDE_REALMATH_SIGN_H

#include "realmath.base.h"


namespace kuma
{
	constexpr sign_t sign(float32_t x)noexcept
	{
		return x > 0.0f ? 1 : (x < -0.0f ? -1 : 0);
	}

	constexpr sign_t sign(float64_t x)noexcept
	{
		return x > 0.0 ? 1 : (x < -0.0 ? -1 : 0);
	}
}


#endif