#pragma once
#include <iostream>

class Dog
{
private:
	int mAge;
public:
	int GetAge();
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

