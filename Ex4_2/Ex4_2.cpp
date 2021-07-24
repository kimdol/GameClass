#include <iostream>

int main()
{
    /*중간점검 연습문제 1-1*/
    /*{
        const int TMPNUM{ 24 };
        int  pascal[TMPNUM][TMPNUM]{};
        int m{ 1 }, n{ 1 };

        pascal[1][TMPNUM / 2] = 1;

        while (m < 6)
        {
            for (n = 1; n < TMPNUM-1; n++)
            {
                if (!((m == 1) && (n == TMPNUM / 2)))
                {
                    pascal[m][n] = pascal[m - 1][n - 1] + pascal[m - 1][(n - 1) + 2];
                }
                else
                {}

                if (0 < pascal[m][n])
                {
                    std::cout << pascal[m][n];
                }
                else if (pascal[m][n] == 0)
                {
                    std::cout << " ";
                }
            } 
            std::cout << "\n";
            m++;
        }


    }*/
    /*중간점검 연습문제 1-2*/
    /*{
        const int MAX{ 10 };
        int cnt{ 0 }, nxt{ 0 }, i{ 0 }, k{ 0 }, res{ 0 };
        int txt[MAX][MAX]{};

        while (1)
        {
            switch (nxt)
            {
                case 0:
                    if ((cnt++ < MAX - 1) && (txt[i][k] < 1))
                    {
                        txt[i][k++] = ++res;
                    }
                    else
                    {
                        nxt++;
                        cnt = 0;
                        if (txt[i][k] >= 1)
                        {
                            i++;
                            k--;
                        }
                    }
                    break;
                case 1:
                    if ((cnt++ < MAX - 1) && (txt[i][k] < 1))
                    {
                        txt[i++][k] = ++res;
                    }
                    else
                    {
                        nxt++;
                        cnt = 0;
                        if (txt[i][k] >= 1)
                        {
                            i--;
                            k--;
                        }
                    }
                    break;
                case 2:
                    if ((cnt++ < MAX - 1) && (k > 0) && (txt[i][k] < 1))
                    {
                        txt[i][k--] = ++res;
                    }
                    else
                    {
                        nxt++;
                        cnt = 0;
                        if (txt[i][k] >= 1)
                        {
                            i--;
                            k++;
                        }
                    }
                    break;
                case 3:
                    if ((cnt++ < MAX - 1) && (txt[i][k] < 1))
                    {
                        txt[i--][k] = ++res;
                    }
                    else
                    {
                        nxt = 0;
                        cnt = 0;
                        if (txt[i][k] >= 1)
                        {
                            i++;
                            k++;
                        }
                    }
                    break;
                default:
                    break;
            }
            if (txt[MAX / 2][MAX / 2] > 0)
            {
                break;
            }
        }

        for (i = 0; i < MAX; i++)
        {
            for (k = 0; k < MAX; k++)
            {
                std::cout << txt[i][k] << "\t";
            }
            std::cout << "\n";
        }

    }*/
    /*중간점검 연습문제 1-3*/
    {
        const int MAX{ 7 };
        int cnt{ 0 }, nxt{ 0 }, i{ MAX - 2 }, k{ MAX / 2 }, res{ 1 }, a{ 0 }, b{ 0 };
        int txt[MAX][MAX]{};

        txt[MAX - 2][MAX / 2] = res;

        while (res != (MAX-2)*(MAX-2))
        {
            switch (nxt)
            {
                case 0:
                    if ((0 < i + 1) && (i + 1 < 6) && (0 < k + 1) && (k + 1 < 6))
                    {
                        if (txt[i + 1][k + 1] == 0)
                        {
                            // 오른쪽 대각선 이동
                            txt[++i][++k] = ++res;
                        }
                        else
                        {
                            nxt = 3;
                        } 
                    }
                    else
                    {
                        nxt = 1;
                    }
                    break;
                case 1:
                    if ((0 < k + 1) && (k + 1 < 6))
                    {
                        if (txt[1][k + 1] == 0)
                        {
                            // 맨위로 숫자를 적음
                            i = 1;
                            txt[i][++k] = ++res;
                            // 변환
                            nxt = 0;
                        }
                        else
                        {
                            nxt = 2;
                        }
                    }
                    else
                    {
                        nxt = 2;
                    }
                    break;
                case 2:
                    if ((0 < i + 1) && (i + 1 < 6))
                    {
                        if (txt[i + 1][1] == 0)
                        {
                            // 맨 왼쪽으로 숫자를 적음
                            k = 1;
                            txt[++i][k] = ++res;
                            // 변환
                            nxt = 0;
                        }
                        else
                        {
                            nxt = 3;
                        }
                    }
                    else
                    {
                        nxt = 3;
                    }
                    break;
                case 3:
                    if (txt[i - 1][k] == 0)
                    {
                        // 이전 기준에서 위쪽으로 숫자 적음
                        txt[--i][k] = ++res;
                        // 변환
                        nxt = 0;
                    }
                    break;
                default:
                    break;

            }
        }

        for (i = 0; i < MAX; i++)
        {
            for (k = 0; k < MAX; k++)
            {
                
                std::cout << txt[i][k] << "\t";

                if (i == 1)
                {
                    a += txt[i][k];
                }
                if (k == 1)
                {
                    b += txt[i][k];
                }
            }
            std::cout << "\n";
        }

    }

}
