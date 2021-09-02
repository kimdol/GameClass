#pragma once
#include <iostream>
struct Monster
{
    std::string name{};
    int hp{};

    Monster* pNext{};
};

struct LinkedList
{
    Monster* pHead{};
    Monster* pTail{};
};

Monster* CreateMonster(LinkedList& list, std::string name, int hp);
void PrintMonsters(const LinkedList& list);
int GetContMonsters(const LinkedList& list);
Monster* FindMonster(const LinkedList& list, std::string name);