#ifndef KUMATARO_INCLUDE_REALMATH_NUMBERS_H
#define KUMATARO_INCLUDE_REALMATH_NUMBERS_H

#include <numbers>

#include "realmath.base.h"


namespace kuma
{
	constexpr float64_t e = std::numbers::e;
	constexpr float64_t inv_e = 1.0 / e;
	constexpr float64_t log10e = 0.43429448190325182765112891891661;
	constexpr float64_t pi = std::numbers::pi;
}


#endif