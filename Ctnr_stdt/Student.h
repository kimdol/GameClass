#pragma once
class Student
{
public:
	int mNumber;
	int mScore;
	std::string mName;
public:
	Student(int num, std::string name, int score);
	~Student();

    void Print()
    {
        std::cout <<
            "(" << mNumber << ") " <<
            mName << " : " <<
            mScore <<
            std::endl;
    }
};

