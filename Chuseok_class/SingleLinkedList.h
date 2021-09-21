#pragma once
#include <iostream>

struct Monster
{
	std::string name{};
	int hp{};

	Monster* nxt{};
};
class SingleLinkedList
{
private:
	Monster* mHead;
	Monster* mTail;

public:
	SingleLinkedList();
	~SingleLinkedList();

	Monster* CreateMonster(std::string name, int hp);
	void PrintMonsters();
	int GetContMonsters();
	Monster* FindMonster(std::string name);
	void DeleteAll();
	bool Delete(std::string name);
};

