#include <iostream>

int main(int argc, char* argv[])
{
    /*배열 크기 변경*/
    /*int* pNumbers{ new int[] {4, 8, 5, 3, 1} };

    int* pTemp{ new int[3] };

    for (int i = 0; i < 3; i++)
    {
        pTemp[i] = pNumbers[i];
    }

    delete[] pNumbers;

    pNumbers = pTemp;*/
    /* pointer to pointer */
    /*int number{ 5 };
    int* p = &number;
    int** pp = &p;

    std::cout << pp << " : " <<
        *pp << " : " <<
        **pp << std::endl;*/
    /* 2차원 배열 동적할당(중요) */
    /*
    int row{ 2 }, col{ 3 };

    // int(*array1)[col] = new int[row][col]; 
    // 위에꺼가 안되서 아래 표기가 나옴
    int** array = new int* [row];
    for (int i = 0; i < row; i++)
    {
        array[i] = new int[col];
    }

    for (int i = 0; i < row; i++)
    {
        delete[] array[i];
        array[i] = nullptr;
    }
    delete[] array;
    array = nullptr;
    */
    /* main 함수 */


}
