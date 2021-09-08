#include "Queue.h"

void Initialize(Queue& queue)
{
	queue.count = 0;
	queue.pFront = queue.pRear = nullptr;
}

void Release(Queue& queue)
{
	Element* element = queue.pFront;

	while (element != nullptr)
	{
		Element* next{ element->pNext };
		delete element;
		element = next;
	}
	Initialize(queue);
}

void Enqueue(Queue& queue, int value)
{
	Element* element = new Element;
	element->value = value;
	element->pNext = nullptr;

	if (queue.count == 0)
	{
		queue.pFront = element;
		queue.pRear = element;
	}
	else
	{
		queue.pRear->pNext = element;
		queue.pRear = element;
	}

	queue.count++;
}

bool Dequeue(Queue& queue)
{
	if (queue.count == 0)
	{
		std::cout << "Queue is none!" << std::endl;
		return false;
	}

	Element* element = queue.pFront;
	std::cout << "dequeue : " << element->value
		<< std::endl;

	queue.pFront = element->pNext;

	delete element;
	queue.count--;
	// 늦게 알아채고, 기존함수 최대한 이용
	if (queue.count == 0)
	{
		Initialize(queue);
	}

	return false;
}

void Print(Queue& queue)
{
	Element* element = queue.pFront;

	while (element != nullptr)
	{
		std::cout << element->value << std::endl;
		element = element->pNext;
	}
}
