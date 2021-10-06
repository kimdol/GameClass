#pragma once
template<typename T>
class MyClass
{
	T mValue;

public:
	void Function(T arg);
};

//template<typename T>
//void MyClass<T>::Function(T arg)
//{
//     이건 됨
//}

#include "MyClass.hpp"  // 편법으로 이것도 됨