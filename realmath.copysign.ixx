module;

#include <type_traits>

export module realmath.copysign;

export import realmath.basic;

export namespace kuma
{
	constexpr float64_t copysign_secure(float64_t x, float64_t y)noexcept;
	constexpr float32_t copysign_secure(float32_t x, float32_t y)noexcept;
	float64_t copysign_fast(float64_t x, float64_t y)noexcept;
	float32_t copysign_fast(float32_t x, float32_t y)noexcept;

	constexpr float64_t copysign(float64_t x, float64_t y)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return copysign_secure(x, y);
		}
		else
		{
			return copysign_fast(x, y);
		}
	}

	constexpr float32_t copysign(float32_t x, float32_t y)noexcept
	{
		if(std::is_constant_evaluated())
		{
			return copysign_secure(x, y);
		}
		else
		{
			return copysign_fast(x, y);
		}
	}
}

export namespace kuma
{
	constexpr float64_t copysign_secure(float64_t x, float64_t y)noexcept
	{
		const uint64_t xBits = *(uint64_t*)(float64_t*)(&x);
		const uint64_t yBits = *(uint64_t*)(float64_t*)(&y);
		const uint64_t rBits = xBits & 0x7fffffffffffffffULL | yBits & 0x8000000000000000ULL;
		return *(float64_t*)(uint64_t*)(&rBits);
	}

	constexpr float32_t copysign_secure(float32_t x, float32_t y)noexcept
	{
		const uint32_t xBits = *(uint32_t*)(float32_t*)(&x);
		const uint32_t yBits = *(uint32_t*)(float32_t*)(&y);
		const uint32_t rBits = xBits & 0x7fffffffUL | yBits & 0x80000000UL;
		return *(float32_t*)(uint32_t*)(&rBits);
	}

	inline float64_t copysign_fast(float64_t x, float64_t y)noexcept
	{
		const uint64_t xBits = *(uint64_t*)(float64_t*)(&x);
		const uint64_t yBits = *(uint64_t*)(float64_t*)(&y);
		const uint64_t rBits = xBits & 0x7fffffffffffffffULL | yBits & 0x8000000000000000ULL;
		return *(float64_t*)(uint64_t*)(&rBits);
	}

	inline float32_t copysign_fast(float32_t x, float32_t y)noexcept
	{
		const uint32_t xBits = *(uint32_t*)(float32_t*)(&x);
		const uint32_t yBits = *(uint32_t*)(float32_t*)(&y);
		const uint32_t rBits = xBits & 0x7fffffffUL | yBits & 0x80000000UL;
		return *(float32_t*)(uint32_t*)(&rBits);
	}
}