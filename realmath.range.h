#ifndef KUMATARO_INCLUDE_REALMATH_RANGE_H
#define KUMATARO_INCLUDE_REALMATH_RANGE_H

#include <algorithm>


namespace kuma
{
	template <class T>
	class range
	{
		T l;
		T u;

	public:
		constexpr range(T l, T u)noexcept :
			l(std::min(l, u)), u(std::max(l, u))
		{

		}
		constexpr void lower(T l)noexcept
		{
			this->l = std::min(l, u);
			u = std::max(l, u);
		}
		constexpr void upper(T u)noexcept
		{
			this->u = std::max(l, u);
			l = std::min(l, u);
		}
		constexpr T lower()const noexcept
		{
			return l;
		}
		constexpr T upper()const noexcept
		{
			return u;
		}
		constexpr T length()const noexcept
		{
			return u - l;
		}
		constexpr bool contains(T x)const noexcept
		{
			return l <= x && x <= u;
		}
		
		friend constexpr bool operator==(const range<T>& lhs, const range<T>& rhs)noexcept;
		friend constexpr bool operator!=(const range<T>& lhs, const range<T>& rhs)noexcept;
		friend constexpr bool operator<(const range<T>& lhs, const range<T>& rhs)noexcept;
		friend constexpr bool operator>(const range<T>& lhs, const range<T>& rhs)noexcept;
		friend constexpr bool operator<=(const range<T>& lhs, const range<T>& rhs)noexcept;
		friend constexpr bool operator>=(const range<T>& lhs, const range<T>& rhs)noexcept;
		friend constexpr range<T> operator&(const range<T>& lhs, const range<T>& rhs)noexcept;
		friend constexpr range<T> operator|(const range<T>& lhs, const range<T>& rhs)noexcept;
		friend constexpr T clamp(const T& x, const range<T>& r)noexcept;
	};

	template <class T>
	constexpr bool operator==(const range<T>& lhs, const range<T>& rhs)noexcept
	{
		return lhs.l == rhs.l && lhs.u == rhs.u;
	}

	template <class T>
	constexpr bool operator!=(const range<T>& lhs, const range<T>& rhs)noexcept
	{
		return !(lhs == rhs);
	}

	template <class T>
	constexpr bool operator<(const range<T>& lhs, const range<T>& rhs)noexcept
	{
		return lhs.u < rhs.l;
	}

	template <class T>
	constexpr bool operator>(const range<T>& lhs, const range<T>& rhs)noexcept
	{
		return rhs < lhs;
	}

	template <class T>
	constexpr bool operator<=(const range<T>& lhs, const range<T>& rhs)noexcept
	{
		return !(rhs < lhs);
	}

	template <class T>
	constexpr bool operator>=(const range<T>& lhs, const range<T>& rhs)noexcept
	{
		return !(lhs < rhs);
	}

	template <class T>
	constexpr range<T> operator&(const range<T>& lhs, const range<T>& rhs)noexcept
	{
		return range<T>(std::max(lhs.lower(), rhs.lower()), std::min(lhs.upper(), rhs.upper()));
	}

	template <class T>
	constexpr range<T> operator|(const range<T>& lhs, const range<T>& rhs)noexcept
	{
		return range<T>(std::min(lhs.lower(), rhs.lower()), std::max(lhs.upper(), rhs.upper()));
	}

	template <class T>
	constexpr T clamp(const T& x, const range<T>& r)noexcept
	{
		return std::clamp(x, r.lower(), r.upper());
	}
}


#endif