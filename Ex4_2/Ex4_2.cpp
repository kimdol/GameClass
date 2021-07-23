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
    {
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
  
    }
}
