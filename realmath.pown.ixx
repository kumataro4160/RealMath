module;

#include <cstdint>

export module realmath.pown;

export import realmath.basic;

export namespace realmath
{
	constexpr float64_t pow(float64_t x, std::uint8_t y)noexcept
	{
		const float64_t x2 = x * x;
		const float64_t x4 = x2 * x2;
		const float64_t x8 = x4 * x4;
		const float64_t x16 = x8 * x8;
		const float64_t x32 = x16 * x16;
		const float64_t x64 = x32 * x32;
		const float64_t x128 = x64 * x64;
		float64_t ret = 1.0;
		ret *= (y & 0b00000001) ? x : 1.0;
		ret *= (y & 0b00000010) ? x2 : 1.0;
		ret *= (y & 0b00000100) ? x4 : 1.0;
		ret *= (y & 0b00001000) ? x8 : 1.0;
		ret *= (y & 0b00010000) ? x16 : 1.0;
		ret *= (y & 0b00100000) ? x32 : 1.0;
		ret *= (y & 0b01000000) ? x64 : 1.0;
		ret *= (y & 0b10000000) ? x128 : 1.0;
		return ret;
	}

	constexpr float64_t pow(float64_t x, std::uint16_t y)noexcept
	{
		const float64_t x2 = x * x;
		const float64_t x4 = x2 * x2;
		const float64_t x8 = x4 * x4;
		const float64_t x16 = x8 * x8;
		const float64_t x32 = x16 * x16;
		const float64_t x64 = x32 * x32;
		const float64_t x128 = x64 * x64;
		const float64_t x256 = x128 * x128;
		const float64_t x512 = x256 * x256;
		const float64_t x1024 = x512 * x512;
		const float64_t x2048 = x1024 * x1024;
		const float64_t x4096 = x2048 * x2048;
		const float64_t x8192 = x4096 * x4096;
		const float64_t x16384 = x8192 * x8192;
		const float64_t x32768 = x16384 * x16384;
		float64_t ret = 1.0;
		ret *= (y & 0b0000000000000001) ? x : 1.0;
		ret *= (y & 0b0000000000000010) ? x2 : 1.0;
		ret *= (y & 0b0000000000000100) ? x4 : 1.0;
		ret *= (y & 0b0000000000001000) ? x8 : 1.0;
		ret *= (y & 0b0000000000010000) ? x16 : 1.0;
		ret *= (y & 0b0000000000100000) ? x32 : 1.0;
		ret *= (y & 0b0000000001000000) ? x64 : 1.0;
		ret *= (y & 0b0000000010000000) ? x128 : 1.0;
		ret *= (y & 0b0000000100000000) ? x256 : 1.0;
		ret *= (y & 0b0000001000000000) ? x512 : 1.0;
		ret *= (y & 0b0000010000000000) ? x1024 : 1.0;
		ret *= (y & 0b0000100000000000) ? x2048 : 1.0;
		ret *= (y & 0b0001000000000000) ? x4096 : 1.0;
		ret *= (y & 0b0010000000000000) ? x8192 : 1.0;
		ret *= (y & 0b0100000000000000) ? x16384 : 1.0;
		ret *= (y & 0b1000000000000000) ? x32768 : 1.0;
		return ret;
	}

	constexpr float64_t pow(float64_t x, std::uint32_t y)noexcept
	{
		const float64_t x2 = x * x;
		const float64_t x4 = x2 * x2;
		const float64_t x8 = x4 * x4;
		const float64_t x16 = x8 * x8;
		const float64_t x32 = x16 * x16;
		const float64_t x64 = x32 * x32;
		const float64_t x128 = x64 * x64;
		const float64_t x256 = x128 * x128;
		const float64_t x512 = x256 * x256;
		const float64_t x1024 = x512 * x512;
		const float64_t x2048 = x1024 * x1024;
		const float64_t x4096 = x2048 * x2048;
		const float64_t x8192 = x4096 * x4096;
		const float64_t x16384 = x8192 * x8192;
		const float64_t x32768 = x16384 * x16384;
		const float64_t x65536 = x32768 * x32768;
		const float64_t x131072 = x65536 * x65536;
		const float64_t x262144 = x131072 * x131072;
		const float64_t x524288 = x262144 * x262144;
		const float64_t x1048576 = x524288 * x524288;
		const float64_t x2097152 = x1048576 * x1048576;
		const float64_t x4194304 = x2097152 * x2097152;
		const float64_t x8388608 = x4194304 * x4194304;
		const float64_t x16777216 = x8388608 * x8388608;
		const float64_t x33554432 = x16777216 * x16777216;
		const float64_t x67108864 = x33554432 * x33554432;
		const float64_t x134217728 = x67108864 * x67108864;
		const float64_t x268435456 = x134217728 * x134217728;
		const float64_t x536870912 = x268435456 * x268435456;
		const float64_t x1073741824 = x536870912 * x536870912;
		const float64_t x2147483648 = x1073741824 * x1073741824;
		float64_t ret = 1.0;
		ret *= (y & 0b00000000000000000000000000000001) ? x : 1.0;
		ret *= (y & 0b00000000000000000000000000000010) ? x2 : 1.0;
		ret *= (y & 0b00000000000000000000000000000100) ? x4 : 1.0;
		ret *= (y & 0b00000000000000000000000000001000) ? x8 : 1.0;
		ret *= (y & 0b00000000000000000000000000010000) ? x16 : 1.0;
		ret *= (y & 0b00000000000000000000000000100000) ? x32 : 1.0;
		ret *= (y & 0b00000000000000000000000001000000) ? x64 : 1.0;
		ret *= (y & 0b00000000000000000000000010000000) ? x128 : 1.0;
		ret *= (y & 0b00000000000000000000000100000000) ? x256 : 1.0;
		ret *= (y & 0b00000000000000000000001000000000) ? x512 : 1.0;
		ret *= (y & 0b00000000000000000000010000000000) ? x1024 : 1.0;
		ret *= (y & 0b00000000000000000000100000000000) ? x2048 : 1.0;
		ret *= (y & 0b00000000000000000001000000000000) ? x4096 : 1.0;
		ret *= (y & 0b00000000000000000010000000000000) ? x8192 : 1.0;
		ret *= (y & 0b00000000000000000100000000000000) ? x16384 : 1.0;
		ret *= (y & 0b00000000000000001000000000000000) ? x32768 : 1.0;
		ret *= (y & 0b00000000000000010000000000000000) ? x65536 : 1.0;
		ret *= (y & 0b00000000000000100000000000000000) ? x131072 : 1.0;
		ret *= (y & 0b00000000000001000000000000000000) ? x262144 : 1.0;
		ret *= (y & 0b00000000000010000000000000000000) ? x524288 : 1.0;
		ret *= (y & 0b00000000000100000000000000000000) ? x1048576 : 1.0;
		ret *= (y & 0b00000000001000000000000000000000) ? x2097152 : 1.0;
		ret *= (y & 0b00000000010000000000000000000000) ? x4194304 : 1.0;
		ret *= (y & 0b00000000100000000000000000000000) ? x8388608 : 1.0;
		ret *= (y & 0b00000001000000000000000000000000) ? x16777216 : 1.0;
		ret *= (y & 0b00000010000000000000000000000000) ? x33554432 : 1.0;
		ret *= (y & 0b00000100000000000000000000000000) ? x67108864 : 1.0;
		ret *= (y & 0b00001000000000000000000000000000) ? x134217728 : 1.0;
		ret *= (y & 0b00010000000000000000000000000000) ? x268435456 : 1.0;
		ret *= (y & 0b00100000000000000000000000000000) ? x536870912 : 1.0;
		ret *= (y & 0b01000000000000000000000000000000) ? x1073741824 : 1.0;
		ret *= (y & 0b10000000000000000000000000000000) ? x2147483648 : 1.0;
		return ret;
	}

	constexpr float64_t pow(float64_t x, std::int8_t y)noexcept
	{
		if(y >= 0)
		{
			return pow(x, static_cast<std::uint8_t>(y));
		}
		else
		{
			return 1.0 / pow(x, static_cast<std::uint8_t>(-y));
		}
	}

	constexpr float64_t pow(float64_t x, std::int16_t y)noexcept
	{
		if(y >= 0)
		{
			return pow(x, static_cast<std::uint16_t>(y));
		}
		else
		{
			return 1.0 / pow(x, static_cast<std::uint16_t>(-y));
		}
	}

	constexpr float64_t pow(float64_t x, std::int32_t y)noexcept
	{
		if(y >= 0)
		{
			return pow(x, static_cast<std::uint32_t>(y));
		}
		else
		{
			return 1.0 / pow(x, static_cast<std::uint32_t>(-y));
		}
	}
}