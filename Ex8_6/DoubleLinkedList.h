#pragma once
#include <iostream>
struct Monster2
{
    std::string name{};
    int hp{};

    Monster2* pNext{};
    Monster2* pPrev{};
};

struct DoubleLinkedList
{
    Monster2* pHead{};
    Monster2* pTail{};
};

Monster2* CreateMonster(DoubleLinkedList& list, std::string name, int hp);
void PrintMonsters(const DoubleLinkedList& list);
void PrintMonsters2(const Monster2* head);
int GetContMonsters(const DoubleLinkedList& list);
Monster2* FindMonster(const DoubleLinkedList& list, std::string name);
void DeleteAll(DoubleLinkedList& list);
bool Delete(DoubleLinkedList& list, std::string name);
Monster2* OneMonster2(std::string name, int hp);
void Insert(DoubleLinkedList& list, std::string name, int way, Monster2* newmon);
