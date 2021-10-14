#include <iostream>
#include <vector>
#include <map>
#include "Student.h"

Student::Student(int num, std::string name, int score) : mNumber{ num }, mName { name }, mScore{ score }
{

}

Student::~Student()
{
}
