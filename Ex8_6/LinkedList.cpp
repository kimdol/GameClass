#include "LinkedList.h"
// ����
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

	return elem; // Ȥ�ó� ���� ���� ����� ���!
}
// ��� 1
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
// ��� 2
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
// ��������
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
// ã��
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
// ��� �����
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
// ã�Ƽ� �����
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
		// 1���� ����ų��
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
		// �߰�
		previous->pNext = element->pNext;
	}

	delete element;

	return true;
}
// JuHo�� ����ֱ� �Լ�
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

	// ������(0:����, 1:������)
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

