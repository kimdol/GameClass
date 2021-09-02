#include <iostream>
#include "LinkedList.h"

int main()
{
    /*링크드 리스트*/
    LinkedList myList;

    CreateMonster(myList, "Wolf", 10);
    CreateMonster(myList, "Slime", 5);
    CreateMonster(myList, "Dragon", 100);

    PrintMonsters(myList);

    std::cout << "Count : " << GetContMonsters(myList)
        << std::endl;

    std::cout << "Wolfl : " 
        << ((FindMonster(myList, "Wolfl")) ? "find!!" : "none")
        << std::endl;
}
