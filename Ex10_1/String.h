#pragma once
#include <iostream>

class String
{
private:
	char* mStr;
public:
	String() : String("\0") {}
	String(const char* cpyStr);
	String(const String& cpyStr);
	~String();

	//prt(<<)
	friend std::ostream& operator<<(std::ostream& os, const String& str1);
	// +
	String operator +(const String& str2);
	// =
	String& operator = (const String& str2);
	// +=
	String& operator+=(const String& str2);
	// []
	char& operator[](int index);
};

// prt
std::ostream& operator<<(std::ostream& os, const String& str1);

