#include <iostream>

int main()
{
    /*중간점검 연습문제 1-1*/
    {
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

       
    }
}
