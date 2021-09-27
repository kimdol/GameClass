#include "String.h"

String::String(const char* cpyStr)
{
	int len{ 0 };
	while (cpyStr[len] != '\0')
	{
		len++;
	}

	mStr = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		mStr[i] = cpyStr[i];
	}
	mStr[len] = '\0';

}

String::String(const String& cpyStr)
{
	int len{ 0 };
	while (cpyStr.mStr[len] != '\0')
	{
		len++;
	}

	mStr = new char[len + 1];
	for (int i = 0; i < len; i++)
	{
		mStr[i] = cpyStr.mStr[i];
	}
	mStr[len] = '\0';
}

String::~String()
{
	delete[] mStr;
}

String String::operator+(const String& str2)
{
	// 갯수 세기
	int len1{ 0 }, len2{ 0 };
	while (mStr[len1] != '\0')
	{
		len1++;
	}
	while (str2.mStr[len2] != '\0')
	{
		len2++;
	}
	// 복사
	char* str{ new char[len1 + len2 + 1] };
	int i{ 0 };
	len1 = len2 = 0;
	while (mStr[len1] != '\0')
	{
		str[i++] = mStr[len1++];
	}
	while (str2.mStr[len2] != '\0')
	{
		str[i++] = str2.mStr[len2++];
	}
	str[len1 + len2] = '\0';

	return String{ str };
}

String& String::operator=(const String& str2)
{
	int len1{ 0 }, len2{ 0 };
	while (mStr[len1] != '\0')
	{
		len1++;
	}
	while (str2.mStr[len2] != '\0')
	{
		len2++;
	}
	// 아래꺼를 수행하기 위함
	if (len1 < len2)
	{
		delete[] mStr;
		mStr = new char[len2 + 1];
	}
	// 복사
	for (int i = 0; i < len2; i++)
	{
		mStr[i] = str2.mStr[i];
	}
	mStr[len2] = '\0';

	return *this;
}

String& String::operator+=(const String& str2)
{
	*this = *this + str2;
	return *this;
}

char& String::operator[](int index)
{
	return mStr[index];
}

std::ostream& operator<<(std::ostream& os, const String& str1)
{
	os << "\"" << str1.mStr << "\"" << std::endl;
	return os;
}
