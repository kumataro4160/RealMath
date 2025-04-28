#ifndef KUMATARO_INCLUDE_REALMATH_BASE_H
#define KUMATARO_INCLUDE_REALMATH_BASE_H


namespace kuma
{

#ifndef KUMATARO_DEFINE_FLOAT_TYPE
#define KUMATARO_DEFINE_FLOAT_TYPE

	using float64_t = double;
	using float32_t = float;

#endif

	using sign_t = signed char;
	using whole_t = signed long long;
}


#endif