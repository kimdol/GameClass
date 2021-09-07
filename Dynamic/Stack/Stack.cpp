#include "Stack.h"
/*게임 프로그래밍에서 필수 함수*/
void Initialize(Stack& stack)
{
	stack.count = 0;
	stack.top = nullptr;
}
void Release(Stack& stack)
{
	Element* element{ stack.top };
	Element* next{};

	while (element)
	{
		next = element->pNext;
		delete element;
		element = next;
	}

	// 늦게 알아챔(필수로 들어가야함)
	Initialize(stack);
}
/*일반 함수*/
void Push(Stack& stack, int value)
{
	// 생성하기
	Element* newElem = new Element{ value, nullptr };
	// 생성한것의 next 넣기
	newElem->pNext = stack.top;
	// top 옮기기
	stack.top = newElem;

	// 카운트 갯수 세기(늦게 알아챔)
	stack.count++;
}
bool Pop(Stack& stack)
{
	// 다 설계한 후에 예외처리해야함
	if (stack.top == nullptr)
	{
		std::cout << "======================"
			<< std::endl;
		std::cout << "stack is none!!" << std::endl;
		std::cout << "======================"
			<< std::endl;
		return false;
	}
	// top 옮기기하다가 필요성이 느껴서 붙임
	// 또는 next를 썻는데 존재하지 않는 변수라고
	// 뜨니까 작성함
	Element* next{ stack.top->pNext };

	// delete
	delete stack.top;
	// top 옮기기
	stack.top = next;
	// 카운트 갯수 세기(늦게 알아챔)
	stack.count--;

	return true;
}
void Print(Stack& stack)
{
	Element* elem{ stack.top };
	if (!elem)
	{
		return;
	}
	// count도 늦게 알아채고 후에 넣음
	std::cout << "===========stack:"
		<< stack.count << "==========="
		<< std::endl;
	while (elem)
	{
		std::cout << elem->value
			<< std::endl;
		elem = elem->pNext;
	}
	std::cout << "==========================="
		<< std::endl;
}

