#pragma once
#include <iostream>
#include <cmath>

class Point2D
{
private:
	int mX;
	int mY;
public:
	Point2D(int x, int y);
	~Point2D();
public:
	void Setting(int x, int y);
	void Print() const;
	void Length() const;
};

