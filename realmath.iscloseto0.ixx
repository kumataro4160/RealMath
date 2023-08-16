export module realmath.iscloseto0;

export import realmath.basic;
import realmath.numeric_limits;
import realmath.abs;

export namespace kuma
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