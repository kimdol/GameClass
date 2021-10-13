#include <iostream>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>

int main()
{
    /******순차컨테이너******/
    // stl deque
    /*std::deque<int> deque{ 3, 4, 5 };
    
    deque.push_back(5);
    deque.push_front(1);

    for (auto e : deque)
    {
        std::cout << e << std::endl;
    }*/
    /***********end************/
    /******보조컨테이너(특수 목적)******/
    // stl stack(순회가 불가능, Top에만 집중함)
    /*std::stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::stack<int> temp(stack);
    while (!temp.empty())
    {
        std::cout << temp.top() << std::endl;
        temp.pop();
    }*/
    // stl queue(순회 불가능)
    /*std::queue<int> queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    std::queue<int> temp(queue);
    while (!temp.empty())
    {
        std::cout << temp.front() << std::endl;
        temp.pop();
    }*/
    // stl priority_queue
    /*std::priority_queue<int> queue;

    queue.push(1);
    queue.push(5);
    queue.push(2);
    queue.push(48);
    queue.push(3);

    std::priority_queue<int> temp(queue);
    while (!temp.empty())
    {
        std::cout << temp.top() << std::endl;
        temp.pop();
    }*/
    /***********end************/
    // stl set
    /*std::set<int> set;

    set.insert(1);
    set.insert(6);
    set.insert(2);
    set.insert(5);
    set.insert(1);

    for (auto e : set)
    {
        std::cout << e << std::endl;
    }*/
    // stl map
    /*  std::map<int, std::string> quests;

    std::pair<int, std::string> pair;
    pair.first = 1;
    pair.second = "Tutorial";
    quests.insert(pair);

    std::pair<int, std::string> q2(2, "Save villiage");
    quests.insert(q2);

    // quests.insert({ 1, "Tutorial" });
    // quests.insert({ 2, "Save villiage" });
    quests.insert({ 3, "hi" });

    for (auto pair : quests)
    {
        std::cout << pair.first
            << " : "<< pair.second
            << std::endl;
    }

    quests[2] = "Save Town";

    std::map<std::string, std::string> myDic;
    myDic.insert({ "array", "순차 컨테이너" });
    myDic.insert({ "stack", "보조 컨테이너" });
    myDic.insert({ "map", "연관 컨테이너" });

    std::cout << myDic["array"] << std::endl; */
    // stl bitset
    /*  std::bitset<4> flag{8};

    // 1 : 0001
    // 3 : 0100
    flag |= 0b0001;
    flag |= 0b0100;

    flag.set(0, 1);
    flag.set(2, 1);

    flag[0] = 1;
    flag[2] = 1;
    if (flag[0] && flag[2])
    {

    }
    
    std::cout << flag << std::endl; */
    

    

}
