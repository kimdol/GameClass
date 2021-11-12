#include <iostream>
#include <random>

int main()
{
    /*C언어에서 지원*/
    /*   {
        srand(static_cast<unsigned int>(time(nullptr))); // 시드(시작값(변수))

        // 유사난수(pseudo-random)
        for (int i = 0; i < 40; i++)
        {
            // 0 ~ 32767
            // 0 ~ 9
            std::cout << rand() % 10 << " ";

        }

        std::cout << std::endl << std::endl;
    }
    */

    /* C++에서 지원 */
    /*  {
        std::random_device rd;
        std::mt19937 gen{ rd() };   // funtor(함수 + 객체)

        for (int i = 0; i < 40; i++)
        {
            std::cout << gen() % 10 << " ";
        }
        std::cout << std::endl << std::endl;

        std::uniform_int_distribution<> dist(0, 9);
        for (int i = 0; i < 50; i++)
        {
            std::cout << dist(gen) << " ";
        }
        std::cout << std::endl << std::endl;
    }
    */

    std::vector<int> deck{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };

    // TODO : Shuffle
    std::random_device rd;
    std::mt19937 gen{ rd() };   // funtor(함수 + 객체)
    std::uniform_int_distribution<> dist(0, deck.size() - 1);
    
    /*for (auto e : deck)
    {
        std::swap(deck[dist(gen)], deck[dist(gen)]);
    }*/
    std::shuffle(deck.begin(), deck.end(), gen);

    for (auto e : deck)
    {
        std::cout << e << " ";
    }
}
