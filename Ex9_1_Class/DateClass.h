#pragma once
#include <iostream>
class DateClass
{
private:
	int mDay;
	int mMonth;
	int mYear;
public:
	DateClass(int year = 0, int month = 0, int day = 0);
	void Print();
};

