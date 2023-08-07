module;

#include <utility>

export module realmath.range;

export namespace realmath
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
	};
}