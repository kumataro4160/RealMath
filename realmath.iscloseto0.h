#ifndef KUMATARO_INCLUDE_REALMATH_ISCLOSETO0_H
#define KUMATARO_INCLUDE_REALMATH_ISCLOSETO0_H

#include "realmath.base.h"
#include "realmath.numeric_limits.h"
#include "realmath.abs.h"


namespace kuma
{
	constexpr bool iscloseto0(float64_t x, float64_t threshold = float64_t_min)noexcept
	{
		return abs(x) < threshold;
	}

	constexpr bool iscloseto0(float32_t x, float32_t threshold = float32_t_min)noexcept
	{
		return abs(x) < threshold;
	}
}


#endif