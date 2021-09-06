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
// 출력 1
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
// 출력 2
void PrintMonsters2(const Monster* element)
{
	// base case
	if (element == nullptr)
	{
		return;
	}
	std::cout << element->name << " : "
		<< element->hp << std::endl;
	// recirsove case
	PrintMonsters2(element->pNext);

}
// 개수세기
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
// 찾기
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
// 모두 지우기
void DeleteAll(LinkedList& list)
{
	Monster* element{ list.pHead };

	// Traverse
	while (element != nullptr)
	{
		Monster* next = element->pNext;
		delete element;

		element = next;
	}

	list.pHead = list.pTail = nullptr;
}
// 찾아서 지우기
bool Delete(LinkedList& list, std::string name)
{
	Monster* element{ list.pHead };
	Monster* previous{ nullptr };

	while (element != nullptr)
	{
		if (element->name == name)
		{
			break;
		}

		previous = element;
		element = element->pNext;
	}

	if (element == nullptr)
	{
		return false;
	}

	if (list.pHead == list.pTail)
	{
		// 1개를 가리킬때
		list.pHead = list.pTail = nullptr;
	}
	else if (element == list.pHead)
	{
		// head
		list.pHead = element->pNext;
	}
	else if (list.pTail == element)
	{
		// tail
		list.pTail = previous;
		previous->pNext = nullptr;
	}
	else
	{
		// 중간
		previous->pNext = element->pNext;
	}

	delete element;

	return true;
}
// JuHo의 집어넣기 함수
Monster* OneMonster(std::string name, int hp)
{
	Monster* elem = new Monster{ name, hp };
	return elem;
}
void Insert(LinkedList& list, std::string name, int way, Monster* newMon)
{
	Monster* element{ list.pHead };
	Monster* prev{};

	// Traverse
	while (element != nullptr)
	{
		if (element->name == name)
		{
			break;
		}
		prev = element;
		element = element->pNext;
	}
	if (element == nullptr || newMon == nullptr)
	{
		std::cout << "element, newMon is nullptr"
			<< std::endl;
		return;
	}

	// 갈림길(0:왼쪽, 1:오른쪽)
	switch (way)
	{
		case 0:
			if (element == list.pHead)
			{
				list.pHead = newMon;
			}
			else
			{
				prev->pNext = newMon;
			}
			newMon->pNext = element;
			break;

		case 1:
			if (element == list.pTail)
			{
				list.pTail = newMon;
			}
			newMon->pNext = element->pNext;
			element->pNext = newMon;
			break;

		default:
			std::cout << "way is invalid" << std::endl;
			break;
	}
}

