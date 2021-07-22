#include <iostream>

int main()
{
    /*테트릭스 게임 만들기*/
    {
        struct block
        {
            int a[3][3]{
                {0, 1, 0},
                {0, 1, 1},
                {0, 1, 0}
            };
        };
        block tetris;
        int flag{ 0x0000 }, command{ 0 };
        int rotBlock[3][3]{};



        while (1)
        {
            if ((flag & 0x0001) == 0x0000)
            {
                for (int row = 0; row)
                std::cout << "왼쪽(1)과 오른쪽(2)을 누르세요. ";
                std::cin >> command;
                flag = 0x0001;
            }
            else if ((flag & 0x0001) == 0x0001)
            {
                for (int row = 0; row)
                if (command == 1)   // 왼쪽 누름
                {
                    rotBlock[2-col][row] = tetris[row][col];
                }
                else if (command == 2) // 오른쪽 누름
                {
                    rotBlock[col][2-row] = tetris[row][col];
                }
            }
            else if ()      // 
            {
                for (int row = 0; row < 3; row++)
                {
                    for (int col = 0; col < 3; col++)
                    {
                        tetris[row][col] = rotBlock[row][col];
                    }
                }
            }
        }
    }
}
