#pragma once
#include <iostream>
class Student
{
private:
	std::string mName;
	int mScore;
	
public:
	void Print();
	Student(std::string name = "", int score = 0);
};

