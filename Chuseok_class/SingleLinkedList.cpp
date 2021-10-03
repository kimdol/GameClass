#include "SingleLinkedList.h"

SingleLinkedList::SingleLinkedList() : mHead{ nullptr }, mTail{ nullptr }
{

}

SingleLinkedList::~SingleLinkedList()
{
	DeleteAll();
}

Monster* SingleLinkedList::CreateMonster(std::string name, int hp)
{
	Monster* elem = new Monster{ name, hp, nullptr };

	if (mTail == nullptr)
	{
		mHead = elem;
		mTail = elem;
	}
	else
	{
		mTail->nxt = elem;
		mTail = elem;
	}

	return elem;
}

void SingleLinkedList::PrintMonsters()
{
	Monster* element{ mHead };
	std::cout <<
		"======================="
		<< std::endl;
	// Traverse
	while (element != nullptr)
	{
		std::cout << element->name << " : "
			<< element->hp << std::endl;
		element = element->nxt;
	}
	std::cout <<
		"======================="
		<< std::endl;
}

int SingleLinkedList::GetContMonsters()
{
	return 0;
}

Monster* SingleLinkedList::FindMonster(std::string name)
{
	Monster* element{ mHead };

	// Traverse
	while (element != nullptr)
	{
		if (element->name == name)
		{
			return element;
		}
		element = element->nxt;
	}
	return nullptr;
}

void SingleLinkedList::DeleteAll()
{
	Monster* element{ mHead };

	// Traverse
	while (element != nullptr)
	{
		Monster* next = element->nxt;
		delete element;

		element = next;
	}

	mHead = mTail = nullptr;
}

bool SingleLinkedList::Delete(std::string name)
{
	Monster* element{ mHead };
	Monster* previous{ nullptr };

	while (element != nullptr)
	{
		if (element->name == name)
		{
			break;
		}

		previous = element;
		element = element->nxt;
	}

	if (element == nullptr)
	{
		return false;
	}

	if (mHead == mTail)
	{
		// 1개를 가리킬때
		mHead = mTail = nullptr;
	}
	else if (element == mHead)
	{
		// head
		mHead = element->nxt;
	}
	else if (mTail == element)
	{
		// tail
		mTail = previous;
		previous->nxt = nullptr;
	}
	else
	{
		// 중간
		previous->nxt = element->nxt;
	}

	delete element;

	return true;
}
