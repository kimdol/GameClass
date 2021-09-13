#pragma once
#include <iostream>
#include <cmath>

class Point2D
{
private:
	int mX;
	int mY;
public:
	void Setting(int x, int y);
	void PointDraw() const;
};

