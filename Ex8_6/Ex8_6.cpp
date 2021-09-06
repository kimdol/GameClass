#include <iostream>
#include "LinkedList.h"
#include "DoubleLinkedList.h"

int main()
{
    /*싱글 링크드 리스트*/
    /*LinkedList myList;

    CreateMonster(myList, "Wolf", 10);
    CreateMonster(myList, "Slime", 5);
    CreateMonster(myList, "Dragon", 100);

    std::cout << "=========prt==========" << std::endl;
    PrintMonsters(myList);
    std::cout << "=======================" << std::endl;
    std::cout << "========prt2===========" << std::endl;
    PrintMonsters2(myList.pHead);
    std::cout << "=======================" << std::endl;

    Insert(myList, "Dragon", 1, OneMonster("juho", 1));
    std::cout << "=======Insert============" << std::endl;
    PrintMonsters2(myList.pHead);
    std::cout << "=========================" << std::endl;

    std::cout << "Count : " << GetContMonsters(myList)
        << std::endl;

    std::cout << "Slime : " 
        << ((FindMonster(myList, "Slime")) ? "find!!" : "none")
        << std::endl;

    Delete(myList, "Slime");
    Delete(myList, "Dragon");
    std::cout << "=========delete==========" << std::endl;
    PrintMonsters2(myList.pHead);
    std::cout << "========================" << std::endl;


    DeleteAll(myList);*/
    /*더블 링크드 리스트*/
    DoubleLinkedList myList;

    CreateMonster(myList, "Wolf", 10);
    CreateMonster(myList, "Slime", 5);
    CreateMonster(myList, "Dragon", 100);

    std::cout << "=======prt============" << std::endl;
    PrintMonsters(myList);
    std::cout << "======================\n" << std::endl;

    Delete(myList, "Wolf");
    Delete(myList, "Slime");
    Delete(myList, "Dragon");
    std::cout << "=======delte_result============" << std::endl;
    PrintMonsters(myList);
    std::cout << "==============================\n" << std::endl;

    std::cout << "=======count============" << std::endl;
    std::cout << GetContMonsters(myList)
        << std::endl;
    std::cout << "========================\n" << std::endl;


    DeleteAll(myList);

}
