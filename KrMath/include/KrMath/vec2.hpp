#pragma once

#define _USE_MATH_DEFINES
#include <cmath>

namespace KrMath
{

	template<typename T>
	struct Vec2
	{
		T x;
		T y;

		Vec2()
			: x(T()), y(T())
		{
		}
		Vec2(T x, T y)
			: x(x), y(y)
		{
		}

		T Length() const
		{
			return sqrt(x * x + y * y);
		}
		T Distance(const Vec2<T>& vec)
		{
			T dx = vec.x - x;
			T dy = vec.y - y;
			return sqrt(dx * dx + dy * dy);
		}
		void Normalize()
		{
			T length = Length();
			x /= length;
			y /= length;
		}
		Vec2<T> Normalized() const
		{
			T length = Length();
			return Vec2<float>(x / length, y / length);
		}
		T DotProduct(const Vec2<T>& vec) const
		{
			return x * vec.x + y * vec.y;
		}
		T Angle(const Vec2<T>& vec) const
		{
			return acos(DotProduct(vec) / (Length() * vec.Length()));
		}

		Vec2<T> operator+(const Vec2<T>& vec)
		{
			return Vec2<T>(x + vec.x, y + vec.y);
		}
		Vec2<T> operator-(const Vec2<T>& vec)
		{
			return Vec2<T>(x - vec.x, y - vec.y);
		}
		Vec2<T> operator*(const Vec2<T>& vec)
		{
			return Vec2<T>(x * vec.x, y * vec.y);
		}
		Vec2<T> operator/(const Vec2<T>& vec)
		{
			return Vec2<T>(x / vec.x, y / vec.y);
		}
	};

}