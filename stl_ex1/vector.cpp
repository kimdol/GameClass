    // STL(����) ����
    /*  std::vector<int> v{2, 3, 1, 5, 6};

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << std::endl;
    }
    // range-based loop (���� ��� �ݺ���)
    for (int x : v) // -> [ 0 : size() )
    {
        std::cout << x << std::endl;
    } */
    // STL(����) ����1
    /*std::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    v.pop_back();

    for (int e : v)
    {
        std::cout << e << std::endl;
    }*/
    // STL(����) ����2
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

    std::cout << "�� : "
        << sum << "\n"
        << "��� : "
        << static_cast<float>(sum) / v.size()
        << std::endl;*/
    // STL(����) ����3
    /*  std::vector<int>                v{1, 2, 3};
            std::vector<int>::iterator      itr = v.begin();
            auto itr2 = v.begin(); // ��ȯ�� Ÿ���� ���� auto�� ����!

            while (itr != v.end())
            {
                std::cout << *itr;
                itr++;
            }
            */
    // ���� 4
    /*std::vector<int>    v{ 1, 2, 3 };

            for (auto& e : v)
            {
                e = 0;
            }

            for (int e : v)
            {
                std::cout << e << std::endl;
            }*/
    // STL �˰��� ����1
    /*  std::vector<int> v1{2, 1, 3};

            // qsort(v.data(), v.size(), sizeof(int), &IntCompare);
            qsort(v1.data(), v1.size(), sizeof(int),
                [](const void* a, const void* b)
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
            } */