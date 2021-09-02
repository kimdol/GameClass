#include "LinkedList.h"
// 생성
Monster* CreateMonster(LinkedList& list, std::string name, int hp)
{
	Monster* elem = new Monster;

	elem->name = name;
	elem->hp = hp;

	if (list.pTail == nullptr)
	{
		list.pHead = elem;
		list.pTail = elem;
	}
	else
	{
		list.pTail->pNext = elem;
		list.pTail = elem;
	}

	return elem; // 혹시나 쓰고 싶은 사람은 써라!
}
void PrintMonsters(const LinkedList& list)
{
	Monster* element{ list.pHead };

	// Traverse
	while (element != nullptr)
	{
		std::cout << element->name << " : "
			<< element->hp << std::endl;
		element = element->pNext;
	}
}
int GetContMonsters(const LinkedList& list)
{
	Monster* element{ list.pHead };
	int cnt{};

	// Traverse
	while (element != nullptr)
	{
		cnt++;
		element = element->pNext;
	}

	return cnt;
}

Monster* FindMonster(const LinkedList& list, std::string name)
{
	Monster* element{ list.pHead };

	// Traverse
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

