#include "DateClass.h"

DateClass::DateClass(int year, int month, int day)
{
	mDay = day;
	mMonth = month;
	mYear = year;
}

void DateClass::Print()
{
	std::cout <<
		mYear << "-" << mMonth << "-" << mDay
		<< std::endl;
}
