#include <iostream>
#include <vector>
#include <algorithm>

// 람다식을 썼을 때 필요가 없어짐
int IntCompare(const void* a, const void* b)
{
    // 내림차순은...
    // -1 : a > b
    // 0 : 같다
    // 1 : a < b
    // 짧은 코딩은 return right - left;
    int left{ *static_cast<const int*>(a) };
    int right{ *static_cast<const int*>(b) };

    if (left > right)
    {
        return -1;
    }
    else if (left < right)
    {
        return 1;
    }
    return 0;

    // 오름차순은...
    // 1 : a > b
    // 0 : 같다
    // -1 : a < b
    // 짧은 코딩은 return left - right;
}

int main()
{
    // STL(벡터) 기초
    /*  std::vector<int> v{2, 3, 1, 5, 6};

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << std::endl;
    }
    // range-based loop (범위 기반 반복문)
    for (int x : v) // -> [ 0 : size() )
    {
        std::cout << x << std::endl;
    } */
    // STL(벡터) 연습1
    /*std::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    v.pop_back();

    for (int e : v)
    {
        std::cout << e << std::endl;
    }*/
    // STL(벡터) 연습2
    /*std::vector<int> v;
    int value, sum{ 0 };

    while (std::cin >> value)
    {
        v.push_back(value);
    }

    for (int e : v)
    {
        sum += e;
    }

    std::cout << "합 : "
        << sum << "\n"
        << "평균 : " 
        << static_cast<float>(sum) / v.size()
        << std::endl;*/
    // STL(벡터) 연습3
    /*  std::vector<int>                v{1, 2, 3};
    std::vector<int>::iterator      itr = v.begin();
    auto itr2 = v.begin(); // 반환값 타입을 보고 auto를 추측!

    while (itr != v.end())
    {
        std::cout << *itr;
        itr++;
    }
    */
    // 연습 4
    /*std::vector<int>    v{ 1, 2, 3 };

    for (auto& e : v)
    {
        e = 0;
    }

    for (int e : v)
    {
        std::cout << e << std::endl;
    }*/
    // STL 알고리즘 연습1
    std::vector<int> v1{ 2, 1, 3 };

    // qsort(v.data(), v.size(), sizeof(int), &IntCompare);
    qsort(v1.data(), v1.size(), sizeof(int), 
        [] (const void* a, const void* b)
        {
        return *((int*)b) - *((int*)a);
        }
    );

    std::for_each(v1.begin(), v1.end(), [](int val)
        {
            std::cout << val << std::endl;
        }
    );

    for (auto e : v1)
    {
        std::cout << e << std::endl;
    }
}
