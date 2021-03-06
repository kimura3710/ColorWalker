#pragma once

// Tは未設定の型、宣言時に型を確定させることができる
template<class T>
class Vector2Template
{
public:
	Vector2Template();
	Vector2Template(T x, T y);
	~Vector2Template();
	T x;		// X座標
	T y;		// Y座標
	// 代入演算子
	Vector2Template<T>& operator=(const Vector2Template& vec);
	// 添え字演算子
	T& operator [](int i);	// iは0か1であること
	// 比較演算子
	bool operator==	(const Vector2Template& vec)const;
	bool operator!=	(const Vector2Template& vec)const;
	bool operator<=	(const Vector2Template& vec)const;
	bool operator<	(const Vector2Template& vec)const;
	bool operator>=	(const Vector2Template& vec)const;
	bool operator>	(const Vector2Template& vec)const;
	// 単項演算子
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