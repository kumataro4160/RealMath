#ifndef KUMATARO_INCLUDE_REALMATH_ISCLOSETO0_H
#define KUMATARO_INCLUDE_REALMATH_ISCLOSETO0_H

#include "realmath.base.h"
#include "realmath.numeric_limits.h"
#include "realmath.abs.h"


namespace kuma
{
	constexpr bool iscloseto0(float64_t x)noexcept
	{
		return abs(x) < float64_t_min;
	}

	constexpr bool iscloseto0(float32_t x)noexcept
	{
		return abs(x) < float32_t_min;
	}
}


#endif