#include "Point2D.h"

void Point2D::Setting(int x, int y)
{
	mX = x;
	mY = y;
}

void Point2D::PointDraw() const
{
	std::cout <<
		"(" << mX << ", " << mY << ")"
		<< "\t";
	std::cout <<
		"Distance : " << sqrt(mX*mX + mY*mY)
		<< std::endl;
}
