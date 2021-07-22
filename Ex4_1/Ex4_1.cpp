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
                for (int row = 0; row < 3; row++)
                {
                    for (int col = 0; col < 3; col++)
                    {
                        if (tetris.a[row][col] == 1)
                        {
                            std::cout << "O ";
                        }
                        else
                        {
                            std::cout << "  ";
                        }
                    }
                    std::cout << "\n";
                }
                std::cout << "왼쪽(1)과 오른쪽(2)과 끝내기(3)을 누르세요. ";
                std::cin >> command;
                if (command == 3)
                {
                    flag = 0x1001;
                }
                else
                {
                    flag = 0x0011;
                }      
            }
            else if ((flag & 0x0010) == 0x0010)     // 회전하고 싶을 때
            {
                for (int row = 0; row < 3; row++)
                {
                    for (int col = 0; col < 3; col++)
                    {
                        if (command == 1)   // 왼쪽 누름
                        {
                            rotBlock[2 - col][row] = tetris.a[row][col];
                        }
                        else if (command == 2) // 오른쪽 누름
                        {
                            rotBlock[col][2 - row] = tetris.a[row][col];
                        }
                    }
                }
                flag = 0x0101;
            }
            else if ((flag & 0x0100) == 0x0100)      // 회전처리 다했을 때
            {
                for (int row = 0; row < 3; row++)
                {
                    
                    for (int col = 0; col < 3; col++)
                    {
                        tetris.a[row][col] = rotBlock[row][col];
                    }
                }
                flag = 0x0000;
            }
            else if ((flag & 0x1000) == 0x1000)      // 테트릭스 게임을 끝내고 싶을 때
            {
                std::cout << "테트릭스 게임이 종료되었습니다. " << std::endl;
                break;
            }
        }
    }
}
