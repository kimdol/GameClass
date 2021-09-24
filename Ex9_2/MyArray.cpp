#include "MyArray.h"
#include <iostream>

MyArray::MyArray() : MyArray(0)
{

}

MyArray::MyArray(int cnt) : mArr{ new float[cnt] }, mCnt{ cnt }
{
	std::cout << cnt << "개 float형 숫자 입력 : ";
	for (int i = 0; i < cnt; i++)
	{
		std::cin >> mArr[i];
	}
}

MyArray::~MyArray()
{
	delete[] mArr;
}

void MyArray::Prt()
{
	for (int i = 0; i < mCnt; i++)
	{
		std::cout <<
			mArr[i] << " ";
	}
	std::cout << std::endl;
}

int MyArray::GetCnt() const
{
	return mCnt;
}

const float& MyArray::operator[](int index)
{
	return mArr[index];
}

MyArray::operator int()
{
	return (int)mArr[0];
}

MyArray operator -(const MyArray& a, const MyArray& b)
{
	return MyArray(a.GetCnt() - b.GetCnt());
}

MyArray operator--(const MyArray& a)
{
	return MyArray(a.GetCnt() - 1);
}
