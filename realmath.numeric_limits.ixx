module;

#include <cmath>

export module realmath.numeric_limits;

export import realmath.basic;

export namespace realmath
{
	constexpr float64_t float64_t_min = std::numeric_limits<float64_t>::min();
	constexpr float64_t float64_t_max = std::numeric_limits<float64_t>::max();
	constexpr float64_t float64_t_eqs = std::numeric_limits<float64_t>::epsilon();
	constexpr float64_t float64_t_inf = std::numeric_limits<float64_t>::infinity();
	constexpr float64_t float64_t_nan = std::numeric_limits<float64_t>::quiet_NaN();
	constexpr float32_t float32_t_min = std::numeric_limits<float32_t>::min();
	constexpr float32_t float32_t_max = std::numeric_limits<float32_t>::max();
	constexpr float32_t float32_t_eps = std::numeric_limits<float32_t>::epsilon();
	constexpr float32_t float32_t_inf = std::numeric_limits<float32_t>::infinity();
	constexpr float32_t float32_t_nan = std::numeric_limits<float32_t>::quiet_NaN();
}