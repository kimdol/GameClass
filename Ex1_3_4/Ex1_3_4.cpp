#include <iostream>

int main()
{/*
    int inputNum;

    std::cout << "숫자를 입력하시오. ";
    std::cin >> inputNum;
    
    int absoluteNum;

    absoluteNum = inputNum < 0 ? -inputNum : inputNum;

    std::cout << "절대값 : " << absoluteNum << std::endl;*/

    //int inputNum;
    //float money, krwMoney;
    //char kind;
    //std::string evenOdd;
    //const float USDTOWON{ 1146.57f };   // 유니폼 초기화 할 때, 리터럴을 꼬옥! 써줘야한다.
    //const float JPYTOWON{ 10.41f };

    //std::cout << "홀수 짝수 구별 할 숫자를 입력하시오. ";
    //std::cin >> inputNum;

    //evenOdd = (inputNum % 2 == 0) ? "짝수" : "홀수";
    //std::cout << "결과는 " << evenOdd << "입니다." << std::endl;


    //std::cout << "달러(S) 혹은 엔(Y)를 입력하시오. ";
    //std::cin >> money >> kind;

    //if (kind == 'S')
    //{
    //    krwMoney = money * USDTOWON;
    //    std::cout << "결과는 " << krwMoney << "원 입니다." << std::endl;
    //}
    //else if (kind == 'Y')
    //{
    //    krwMoney = money * JPYTOWON;
    //    std::cout << "결과는 " << krwMoney << "원 입니다." << std::endl;
    //}
    /*=========================================================================================================================*/
    /*지하철 요금 계산*/
    //int age, distance, money{ 0 };
    //std::string payTool;

    //std::cout << "지하철의 오신것을 환영합니다. \n";
    //std::cout << "지하철 요금을 위해 질문을 하겠습니다 \n";
    //std::cout << "나이는? ";
    //std::cin >> age;
    //std::cout << "결제 수단(일반 or 선후불)은? ";
    //std::cin >> payTool;
    //std::cout << "거리는?(km단위) ";
    //std::cin >> distance;

    //if (payTool == "선후불")
    //{
    //    if (distance <= 10)
    //    {
    //        if (age <= 18) // 어린이
    //        {
    //            money = 450;
    //        }
    //        else if ((age > 18) && (age <= 24)) // 청소년
    //        {
    //            money = 720;
    //        }
    //        else     // 어른
    //        {
    //            money = 1250;
    //        }
    //    }
    //    else if (distance <= 15)
    //    {
    //        if (age <= 18) // 어린이
    //        {
    //            money = 500;
    //        }
    //        else if ((age > 18) && (age <= 24)) // 청소년
    //        {
    //            money = 800;
    //        }
    //        else     // 어른
    //        {
    //            money = 1350;
    //        }
    //    }
    //    else if (distance <= 20)
    //    {
    //        if (age <= 18) // 어린이
    //        {
    //            money = 550;
    //        }
    //        else if ((age > 18) && (age <= 24)) // 청소년
    //        {
    //            money = 880;
    //        }
    //        else     // 어른
    //        {
    //            money = 1450;
    //        }
    //    }
    //}
    //else if (payTool == "일반")
    //{
    //    if (distance <= 10)
    //    {
    //        if (age <= 18) // 어린이
    //        {
    //            money = 450;
    //        }
    //        else if ((age > 18) && (age <= 24)) // 청소년
    //        {
    //            money = 1350;
    //        }
    //        else     // 어른
    //        {
    //            money = 1350;
    //        }
    //    }
    //    else if (distance <= 15)
    //    {
    //        if (age <= 18) // 어린이
    //        {
    //            money = 500;
    //        }
    //        else if ((age > 18) && (age <= 24)) // 청소년
    //        {
    //            money = 1451;
    //        }
    //        else     // 어른
    //        {
    //            money = 1450;
    //        }
    //    }
    //    else if (distance <= 20)
    //    {
    //        if (age <= 18) // 어린이
    //        {
    //            money = 550;
    //        }
    //        else if ((age > 18) && (age <= 24)) // 청소년
    //        {
    //            money = 1550;
    //        }
    //        else     // 어른
    //        {
    //            money = 1550;
    //        }
    //    }
    //}

    //std::cout << "교통요금은 " << money << "입니다" << std::endl;

    /*=========================================================================================================================*/
    /* BMI 계산*/
    float weight{ 0.0f }, height{ 0.0f }, bmi{ 0.0f };

    std::cout << "BMI 세계에 오신것을 환영합니다. \n";
    std::cout << "BMI 계산을 위해 질문을 하겠습니다 \n";
    std::cout << "체중(kg)은? ";
    std::cin >> weight;
    std::cout << "키(cm)는? ";
    std::cin >> height;

    bmi = weight / ((height * 0.01) * (height * 0.01));
    if (bmi < 20)
    {
        std::cout << "BMI 수치는 " << bmi << "입니다\n";
        std::cout << "축하드립니다 " << "저체중입니다" << std::endl;
    }
    else if ((20 <= bmi) && (bmi <= 24))
    {
        std::cout << "BMI 수치는 " << bmi << "입니다\n";
        std::cout << "축하드립니다 " << "정상입니다" << std::endl;
    }
    else if ((24 < bmi) && (bmi < 30))
    {
        std::cout << "BMI 수치는 " << bmi << "입니다\n";
        std::cout << "축하드립니다 " << "과체충입니다" << std::endl;
        std::cout << "운동을 하십시오" << std::endl;
    }
    else if ((30 <= bmi))
    {
        std::cout << "BMI 수치는 " << bmi << "입니다\n";
        std::cout << "축하드립니다 " << "비만입니다" << std::endl;
        std::cout << "운동을 하십시오" << std::endl;
    }
    

    




}
