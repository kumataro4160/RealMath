#ifndef KUMATARO_INCLUDE_REALMATH_BASE_H
#define KUMATARO_INCLUDE_REALMATH_BASE_H


#ifndef KUMATARO_DEFINE_FLOAT_TYPE
#define KUMATARO_DEFINE_FLOAT_TYPE
namespace kuma
{
	using float64_t = double;
	using float32_t = float;
}
#endif

namespace kuma
{
	using sign_t = signed char;
	using whole_t = signed long long;
}


#endif