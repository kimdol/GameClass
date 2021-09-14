#include "Point2D.h"

Point2D::Point2D(int x, int y)
{
	std::cout << "[생장자]" << std::endl;
	mX = x;
	mY = y;
}

void Point2D::Setting(int x, int y)
{
	mX = x;
	mY = y;
}

void Point2D::Print() const
{
	std::cout <<
		"(" << mX << ", " << mY << ")"
		<< std::endl;
}
void Point2D::Length() const
{
	std::cout <<
		"Distance : " << sqrt(mX * mX + mY * mY)
		<< std::endl;
}

Point2D::~Point2D()
{
	std::cout << "[소멸자]" << std::endl;
}
