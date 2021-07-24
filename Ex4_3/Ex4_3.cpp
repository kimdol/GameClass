#include <iostream>

int main()
{
    /*짝수 마방진*/
    {
        const int MAX{ 4 };
        int cnt{ 0 }, nxt{ 0 }, res{ MAX / 4 };
        int txt[MAX][MAX]{};
        // 짝수 마방진 처리
        for (int i = 0; i < MAX; i++)
        {
            for (int k = 0; k < MAX; k++)
            {
                if (((i < res) || (MAX - res <= i)) && ((k < res) || (MAX - res <= k)))
                {
                    txt[i][k] = ++cnt;
                }
                else if (((res <= k) && (k <= (MAX - 1) - res)) && ((res <= i) && (i <= (MAX - 1) - res)))
                {
                    txt[i][k] = ++cnt;
                }
            }
        }
        for (int i = MAX - 1; i >= 0; i--)
        {
            for (int k = MAX - 1; k >= 0; k--)
            {
                if (txt[i][k] == 0)
                {
                    txt[i][k] = ++cnt;
                }
            }
        }
        // 화면에 출력
        for (int i = 0; i < MAX; i++)
        {
            for (int k = 0; k < MAX; k++)
            {
                std::cout << txt[i][k] << "\t";
            }
            std::cout << "\n";
        }
    }
        
    



}
