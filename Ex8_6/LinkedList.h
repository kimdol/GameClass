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
void PrintMonsters2(const Monster* head);
int GetContMonsters(const LinkedList& list);
Monster* FindMonster(const LinkedList& list, std::string name);
void DeleteAll(LinkedList& list);
bool Delete(LinkedList& list, std::string name);
Monster* OneMonster(std::string name, int hp);
void Insert(LinkedList& list, std::string name, int way, Monster* newmon);


