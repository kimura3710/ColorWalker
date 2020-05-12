#pragma once

// T‚Í–¢İ’è‚ÌŒ^AéŒ¾‚ÉŒ^‚ğŠm’è‚³‚¹‚é‚±‚Æ‚ª‚Å‚«‚é
template<class T>
class Vector2Template
{
public:
	Vector2Template();
	Vector2Template(T x, T y);
	~Vector2Template();
	T x;		// XÀ•W
	T y;		// YÀ•W
	// ‘ã“ü‰‰Zq
	Vector2Template<T>& operator=(const Vector2Template& vec);
	// “Y‚¦š‰‰Zq
	T& operator [](int i);	// i‚Í0‚©1‚Å‚ ‚é‚±‚Æ
	// ”äŠr‰‰Zq
	bool operator==	(const Vector2Template& vec)const;
	bool operator!=	(const Vector2Template& vec)const;
	bool operator<=	(const Vector2Template& vec)const;
	bool operator<	(const Vector2Template& vec)const;
	bool operator>=	(const Vector2Template& vec)const;
	bool operator>	(const Vector2Template& vec)const;
	// ’P€‰‰Zq
	Vector2Template operator+=(const Vector2Template& vec);
	Vector2Template operator-=(const Vector2Template& vec);
	Vector2Template operator*=(const T & k);
	Vector2Template operator/=(const T & k);
	Vector2Template operator+()const;
	Vector2Template operator-()const;
};


template<class T>
Vector2Template<T> operator+(const Vector2Template<T>& u, const T & v);
template<class T>
Vector2Template<T> operator-(const Vector2Template<T>& u, const T & v);
template<class T>
Vector2Template<T> operator+(const Vector2Template<T>& u, Vector2Template<T> & v);
template<class T>
Vector2Template<T> operator-(const Vector2Template<T>& u, Vector2Template<T> & v);
template<class T>
Vector2Template<T> operator*(const T & k, const Vector2Template<T>& v);
template<class T>
Vector2Template<T> operator*(const Vector2Template<T>& v, const T & k);
template<class T>
Vector2Template<T> operator/(const Vector2Template<T>& u, const T & k);
template<class T>
Vector2Template<T> operator%(const Vector2Template<T>& u, const T & k);


using Vector2 = Vector2Template<int>;
using Vector2d = Vector2Template<double>;
using Vector2f = Vector2Template<float>;

#include "./details/Vector2.h"