/*--------------------------------------------------------------------------------------------------
This project was generated in 2013 by Alberto Bobadilla
--------------------------------------------------------------------------------------------------*/
#ifndef _MAIN_H
#define _MAIN_H

#include <iostream>
#include "Foo.h"

template <class T>
T GetMax (T a, T b)
{
	return (a>b?a:b);
}

#pragma region MIX
//template <class T, class U>
//T GetMax (T a, U b)
//{
//	return (a>b?a:b);
//}
#pragma endregion

#pragma region TEMPLATE CLASS
//template <class T, class U, class V>
//class myClass
//{
//public:
//	T x;
//	U y;
//	V z;
//	void Set(T _x, U _y, V _z)
//	{
//		x = _x; 
//		y = _y;
//		z = _z;
//	}
//};
#pragma endregion

#endif //_MAIN_H