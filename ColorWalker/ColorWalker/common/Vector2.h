#pragma once

// T�͖��ݒ�̌^�A�錾���Ɍ^���m�肳���邱�Ƃ��ł���
template<class T>
class Vector2Template
{
public:
	Vector2Template();
	Vector2Template(T x, T y);
	~Vector2Template();
	T x;		// X���W
	T y;		// Y���W
	// ������Z�q
	Vector2Template<T>& operator=(const Vector2Template& vec);
	// �Y�������Z�q
	T& operator [](int i);	// i��0��1�ł��邱��
	// ��r���Z�q
	bool operator==	(const Vector2Template& vec)const;
	bool operator!=	(const Vector2Template& vec)const;
	bool operator<=	(const Vector2Template& vec)const;
	bool operator<	(const Vector2Template& vec)const;
	bool operator>=	(const Vector2Template& vec)const;
	bool operator>	(const Vector2Template& vec)const;
	// �P�����Z�q
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