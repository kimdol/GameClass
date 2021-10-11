#include <iostream>
#include <list>
#include <iterator>
#include <queue>

// list 출력 함수
void ShowList(std::list<int> g)
{
    std::list<int>::iterator it;
    for (it = g.begin(); it != g.end(); it++)
    {
        std::cout << '\t' << *it;
    }
    std::cout << std::endl;
}
// priority_queue 출력 함수
void showpq(std::priority_queue<int> gq)
{
    std::priority_queue<int> g = gq;
    while (!g.empty()) {
        std::cout << '\t' << g.top();
        g.pop();
    }
    std::cout << '\n';
}

int main()
{
    /*list*/
    /*std::list<int> list1, list2;

    for (int i = 0; i < 10; i++)
    {
        list1.push_back(i * 2);
        list2.push_front(i * 3);
    }
    std::cout << "\nList1 is : ";
    ShowList(list1);

    std::cout << "\nList2 is : ";
    ShowList(list2);

    std::cout << "\nlist1.front() : " << list1.front();
    std::cout << "\nlist1.back() : " << list1.back();
    
    std::cout << "\nlist1.pop_front() : ";
    list1.pop_front();
    ShowList(list1);

    std::cout << "\nlist2.pop_back() : ";
    list2.pop_back();
    ShowList(list2);

    std::cout << "\nlist1.reverse() : ";
    list1.reverse();
    ShowList(list1);

    std::cout << "\nlist2.sort(): ";
    list2.sort();
    ShowList(list2);*/
    /*priority_queue*/
    /*std::priority_queue<int> gquiz;
    gquiz.push(10);
    gquiz.push(30);
    gquiz.push(20);
    gquiz.push(5);
    gquiz.push(1);

    std::cout << "The priority queue gquiz is : ";
    showpq(gquiz);

    std::cout << "\ngquiz.size() : " << gquiz.size();
    std::cout << "\ngquiz.top() : " << gquiz.top();

    std::cout << "\ngquiz.pop() : ";
    gquiz.pop();
    showpq(gquiz);*/


}
