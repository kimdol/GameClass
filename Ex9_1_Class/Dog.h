#pragma once
#include <iostream>

class Dog
{
private:
	int mAge;
public:
	int mColor;
public:
	int GetAge() const;
private:
	void Eat() {};
public:
	Dog();
public:
	void aa() {};
};

class Warrior
{
private:
	int mHp;
	int mAd;
	int mBersk;
public:
	void Setting(int hp, int ad, int bersk);
	void Attack(Warrior& attacked);
	void Skill();
};

