#include <iostream>
#include <array>
#include <vector>
#include <forward_list>
#include <list>

int main()
{
    // stl array
    /*std::array<int, 4> intArray{ 0, 1, 2, 3 };

    for (auto e : intArray)
    {
        std::cout << e << std::endl;
    }

    for (auto iter = intArray.begin(); iter != intArray.end();
        iter++)
    {
        std::cout << *iter << std::endl;
    }

    for (int i = 0; i < intArray.size(); i++)
    {
        std::cout << intArray[i] << std::endl;
    }*/
    // stl vector(끝에서 삽입/삭제(특화됨))
    /*std::vector<int> v;
 
    v.push_back(3);
    v.push_back(10);
    v.push_back(20);

    for (auto e : v)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::cout << "pop : " << *(v.end() - 1) << std::endl;
    std::cout << "pop : " << v[v.size() - 1] << std::endl;
    v.pop_back();

    for (auto e : v)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    v.resize(5, 1);
    
    v.erase(v.begin());

    v.clear();*/
    // stl forward_list(c++11)
    /*std::forward_list<int> list{ 10, 11, 20, 21 };
    std::forward_list<int> list2{ 100, 200 };

    list.remove(11);
    for (auto e : list)
    {
        std::cout << e << std::endl;
    }

    auto itr = std::find(list.begin(), list.end(), 20);
    list.insert_after(itr, 30);
    for (auto e : list)
    {
        std::cout << e << std::endl;
    }*/
    // stl forward_list(고급)
    /*  std::forward_list<int> list{10, 11, 21};
    std::forward_list<int> list2{ 100, 200 };

    list.splice_after(std::find
    (list.begin(), list.end(), 21), list2);
    for (auto e : list)
    {
        std::cout << e << std::endl;
    }
    std::cout << std::endl;

    for (auto e : list2)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // c++14 : predicate
    list.sort(std::less<int>()); // greate : 오름차순
    for (auto e : list)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    list.unique(); // 중복되는 숫자를 제거
                 // 단, 정렬이 되어있어야 한다(앞을 못보니까)
    for (auto e : list)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    */
    // stl list
    /*  std::list<int> list1{1, 3, 2, 4};
    std::list<int> list2{ 5, 7, 6, 1 };
    std::list<int> list3{ 5, 7, 6, 1 };
    std::list<int> list4{ 1, 3, 2, 4 };

    list1.splice(list1.end(), list2);
    for (auto e : list1)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // 정렬필수
    list1.sort();
    list1.unique();
    for (auto e : list1)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // 정렬필수
    list4.sort();
    list3.sort();
    list3.merge(list4);
    for (auto e : list3)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl; */
}
