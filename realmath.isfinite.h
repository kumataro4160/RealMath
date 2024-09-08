#ifndef KUMATARO_INCLUDE_REALMATH_ISFINITE_H
#define KUMATARO_INCLUDE_REALMATH_ISFINITE_H

#include "realmath.base.h"
#include "realmath.numeric_limits.h"


namespace kuma
{
	constexpr float32_t isfinite(float32_t x)noexcept
	{
		return x != float32_t_inf && x != -float32_t_inf;
	}

	constexpr float64_t isfinite(float64_t x)noexcept
	{
		return x != float64_t_inf && x != -float64_t_inf;
	}
}


#endif