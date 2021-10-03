#pragma once
#include <iostream>
#include "Monster.h"

class SingleLinkedList
{
protected:
	Monster* mHead;
	Monster* mTail;

public:
	SingleLinkedList();
	virtual ~SingleLinkedList();

	Monster* CreateMonster(std::string name, int hp);
	void PrintMonsters();
	int GetContMonsters();
	Monster* FindMonster(std::string name);
	void DeleteAll();
	bool Delete(std::string name);
};

