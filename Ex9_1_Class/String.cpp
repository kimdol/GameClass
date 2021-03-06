#include "String.h"
#include <iostream>

String::String(const char* string) : mString{}
{
	// string 글자 수 = 문자열의 길이
	int length{ 0 };
	while (string[length] != '\0')
	{
		length++;
	}
	// 길이만큼 메모리 할당
	mString = new char[length + 1];
	// string -> mString으로 복사
	for (int i = 0; i < length; i++)
	{
		mString[i] = string[i];
	}
	mString[length] = '\0';
}

String::~String()
{
	delete[] mString;
	mString = nullptr;
}

void String::Print()
{
	std::cout << mString;
}
