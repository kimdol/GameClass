#include "Student.h"

void Student::Print()
{
	std::cout <<
		mName << " : " << mScore 
		<< std::endl;
}

Student::Student(std::string name, int score)
{
	mName = name;
	mScore = score;
}
