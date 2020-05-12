#pragma once
#include "../Vector2.h"

template<class T>
Vector2Template<T>::Vector2Template()
{
	this->x = 0;
	this->y = 0;
}

template<class T>
Vector2Template<T>::Vector2Template(T x, T y)
{
	this->x = x;
	this->y = y;
}


template<class T>
Vector2Template<T>::~Vector2Template()
{
}

template<class T>
Vector2Template<T> & Vector2Template<T>::operator=(const Vector2Template<T> & vec)
{
	this->x = vec.x;
	this->y = vec.y;
	return *this;
}

template<class T>
T & Vector2Template<T>::operator[](int i)
{
	if (i == 0)
	{
		return this->x;
	}
	else if (i == 1)
	{
		return this->y;
	}
	else
	{
		return this->x;
	}
}

template<class T>
bool Vector2Template<T>::operator==(const Vector2Template<T> & vec)const
{
	return ((this->x == vec.x) && (this->y == vec.y));
}

template<class T>
bool  Vector2Template<T>::operator!=(const Vector2Template<T> & vec)const
{
	return !((this->x == vec.x) && (this->y == vec.y));
}

template<class T>
bool Vector2Template<T>::operator<=(const Vector2Template<T> & vec) const
{
	return ((this->x <= vec.x) && (this->y <= vec.y));
}

template<class T>
bool Vector2Template<T>::operator<(const Vector2Template<T> & vec) const
{
	return ((this->x < vec.x) && (this->y < vec.y));
}

template<class T>
bool Vector2Template<T>::operator>=(const Vector2Template & vec) const
{
	return ((this->x >= vec.x && this->y >= vec.y));
}

template<class T>
bool Vector2Template<T>::operator>(const Vector2Template & vec) const
{
	return ((this->x > vec.x) && (this->y > vec.y));
}

template<class T>
Vector2Template<T> Vector2Template<T>::operator+=(const Vector2Template & vec)
{
	this->x += vec.x;
	this->y += vec.y;
	return *this;
}

template<class T>
Vector2Template<T> Vector2Template<T>::operator-=(const Vector2Template & vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	return *this;
}

template<class T>
Vector2Template<T> Vector2Template<T>::operator*=(const T & k)
{
	this->x *= k;
	this->y *= k;
	return *this;
}

template<class T>
Vector2Template<T> Vector2Template<T>::operator/=(const T & k)
{
	this->x /= k;
	this->y /= k;
	return *this;
}

template<class T>
Vector2Template<T> Vector2Template<T>::operator+() const
{
	return *this;
}

template<class T>
Vector2Template<T> Vector2Template<T>::operator-() const
{
	return Vector2Template(-this->x, -this->y);
}


template<class T>
Vector2Template<T> operator+(const Vector2Template<T> & u, const T & v)
{
	return Vector2(u.x + v,u.y + v);
}

template<class T>
Vector2Template<T> operator-(const Vector2Template<T> & u, const T & v)
{
	return Vector2(u.x - v, u.y - v);
}

template<class T>
Vector2Template<T> operator+(const Vector2Template<T> & u, const Vector2Template<T> & v)
{
	return Vector2(u.x + v.x, u.y + v.y);
}

template<class T>
Vector2Template<T> operator-(const Vector2Template<T> & u, const Vector2Template<T> & v)
{
	return Vector2(u.x - v.x, u.y - v.y);
}

template<class T>
Vector2Template<T> operator*(const T & k, const Vector2Template<T> & v)
{
	return Vector2(k * v.x,k * v.y);
}

template<class T>
Vector2Template<T> operator*(const Vector2Template<T> & v, const T & k)
{
	return Vector2Template<T>(v.x * k,v.y * k);
}

template<class T>
Vector2Template<T> operator/(const Vector2Template<T> & u, const T & k)
{
	return Vector2(u.x / k, u.y / k);
}

template<class T>
Vector2Template<T> operator%(const Vector2Template<T> & u, const T & k)
{
	return Vector2(u.x % k, u.y % k);
}
