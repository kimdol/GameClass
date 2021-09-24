#pragma once
class MyArray
{
private:
	float* mArr;
	int mCnt;

public:
	MyArray();
	MyArray(int cnt);
	~MyArray();

	void Prt();
	int GetCnt() const;
	const float& operator [](int index);
	operator int();

};

MyArray operator -(const MyArray& a, const MyArray& b);
MyArray operator --(const MyArray& a);


