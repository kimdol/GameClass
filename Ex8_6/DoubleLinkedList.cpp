#include "DoubleLinkedList.h"

Monster2* CreateMonster(DoubleLinkedList& list, std::string name, int hp)
{
	Monster2* elem = new Monster2;
	elem->name = name;
	elem->hp = hp;
	elem->pPrev = elem->pNext = nullptr;

	if (list.pHead == nullptr)
	{
		list.pTail = elem;
		list.pHead = elem;
	}
	else
	{
		elem->pPrev = list.pTail;
		list.pTail->pNext = elem;
		list.pTail = elem;
	}

	return elem;
}

void PrintMonsters(const DoubleLinkedList& list)
{
	Monster2* element{ list.pHead };

	while (element != nullptr)
	{
		std::cout << element->name << " : "
			<< element->hp << std::endl;
		element = element->pNext;
	}
}

void PrintMonsters2(const Monster2* head)
{
}

int GetContMonsters(const DoubleLinkedList& list)
{
	Monster2* element{ list.pHead };
	int count{};

	while (element)
	{
		count++;
		element = element->pNext;
	}
	return count;
}

Monster2* FindMonster(const DoubleLinkedList& list, std::string name)
{
	Monster2* element{ list.pHead };

	while (element != nullptr)
	{
		if (element->name == name)
		{
			return element;
		}
		element = element->pNext;
	}
	return nullptr;
}

void DeleteAll(DoubleLinkedList& list)
{
	Monster2* element{ list.pHead };
	Monster2* next;

	while (element != nullptr)
	{
		next = element->pNext;
		delete element;

		element = next;
	}

	list.pHead = list.pTail = nullptr;
}
// if else 정리(간략하게 쓰는법)
bool Delete(DoubleLinkedList& list, std::string name)
{
	Monster2* element{ FindMonster(list, name) };

	if (element != nullptr)
	{
		if (element->pPrev == nullptr)
		{
			list.pHead = element->pNext;
		} else
		{
			element->pPrev->pNext = element->pNext;
		}
		
		if (element->pNext == nullptr)
		{
			list.pTail = element->pPrev;
		} else
		{
			element->pNext->pPrev = element->pPrev;
		}

		delete element;
		return true;
	}

	return false;
}

Monster2* OneMonster2(std::string name, int hp)
{
	return nullptr;
}
void Insert(DoubleLinkedList& list, std::string name, int way, Monster2* newmon)
{
}
