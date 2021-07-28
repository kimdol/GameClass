#include <iostream>
#include <stdarg.h>    // 가변 인자 사용하기 위한 헤더
#include <random>

//int Sum(int num[5])
//{
//    int total{ 0 };
//
//    for (int i = 0; i < 5; i++)
//    {
//        total += num[i];
//    }
//    return total;
//}

void PrintInfo(); // 2번
/*애매모호한 함수 초기값과 오버로딩*/
int BoxArea(int w, int l = 1);
int BoxArea(int size);
/*가변 인자 함수*/
void funcion(int count, ...)
{
    va_list params;
    va_start(params, count);

    for (int i = 0; i < count; ++i)
    {
        std::cout << va_arg(params, int) << " ";
    }
}


int main()
{
    /* 함수 기본 */
    /*{
        std::cout << pow(2, 2) << std::endl;

    }*/
    /*함수에 매개변수로 배열을 사용해 봅시다*/
    /*{
        int num[]{ 1, 2, 3, 4, 5 };

        std::cout << Sum(num) << std::endl;
    }*/
    /*프로그램 만드는 과정*/
    //{
    //    // 1번(프로그램 정보 출력)
    //    PrintInfo();    // 일단 메인에 쓸 함수부터 적고 시작한다
    //}
    /*애매모호한 함수 초기값과 오버로딩*/
    /*{
        std::cout << BoxArea(5) << std::endl;
    }*/
    /*가변 인자 함수 사용중...*/
    /*{
        funcion(3, 1, 3, 4);
    }*/
    /*중간 점검 문제 1-1*/
    /*{
        enum monsterType
        {
            Wolf = 0,
            Demon,
            Slime
        };
        struct monster
        {
            monsterType type;
            std::string name;
            int hp;
        };

        monster underworldWolf{ Wolf, "황천늑대", 10 };
        monster succubus{ Demon, "써큐버스", 100 };
        if (succubus.type == Demon)
        {
            std::cout << "써큐버스는 데몬타입 입니다 " << std::endl;
            std::cout << "총 hp는 " << succubus.hp  << " 입니다" << std::endl;
        }
        
    }*/
    /*중간 점검 문제 1-2*/
    {
        const int TOTAL{ 3 };
        int answer[TOTAL]{}, answerTmp[TOTAL]{}, randomTmp{}, cnt{ 0 }, same{ 0 }, ballRes[TOTAL]{}, input{ 0 }, ballCnt{ 0 }, end{ 0 };
        // 시드값을 얻기 위한 random_device 생성.
        std::random_device rd;
        // random_device 를 통해 난수 생성 엔진을 초기화 한다.
        std::mt19937 gen(rd());
        // 0 부터 99 까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
        std::uniform_int_distribution<int> dis(0, 9);

        while (cnt < 3)
        {
            // 주사위 굴리기
            randomTmp = dis(gen);
            // 주사위 굴린 숫자가 중복되는지 확인
            if (cnt > 0)
            {
                for (int i = 0; i < 3; i++)
                {
                    if (randomTmp == answer[i])
                    {
                        same++;
                    }
                }
            }
            // 적기
            if (same == 0)
            {
                answer[cnt++] = randomTmp;
                answerTmp[cnt - 1] = randomTmp;
            }
            same = 0;
        }

        for (int i = 0; i < 3; i++)
        {
            std::cout << answer[i];
        }
        std::cout << "\n";

        while (1)
        {
            // 숫자 3개 입력받기(항상 처음에 받기)
            if (cnt > TOTAL-1)
            {
                std::cout << "숫자 야구 게임을 시작하겠습니다\n";
                std::cout << "서로 다른 숫자 3자리를 입력해주십시오  ";
                std::cin >> input;
                cnt = 0;
            }
            // 체크
            if (cnt == 0)
            {
                if (input / 100 == answer[cnt]) // 스트라이크 확인
                {
                    answer[cnt] = 99;
                    ballRes[0]++;
                    cnt++;  
                }
                else if (input / 100 == answer[ballCnt++])   // 볼 확인
                {
                    answer[ballCnt - 1] = 99;
                    ballRes[1]++;
                    cnt++;
                    ballCnt = 0;
                }
                else if (ballCnt == TOTAL)    // 아웃 확인 
                {
                    ballRes[2]++;
                    cnt++;
                    ballCnt = 0;
                }
            }
            else if (cnt == 1)
            {
                if ((input % 100) / 10 == answer[cnt]) // 스트라이크 확인
                {
                    answer[cnt] = 99;
                    ballRes[0]++;
                    cnt++;
                }
                else if ((input % 100) / 10 == answer[ballCnt++])   // 볼 확인
                {
                    answer[ballCnt - 1] = 99;
                    ballRes[1]++;
                    cnt++;
                    ballCnt = 0;
                }
                else if (ballCnt == TOTAL)    // 아웃 확인 
                {
                    ballRes[2]++;
                    cnt++;
                    ballCnt = 0;
                } 
            }
            else if (cnt == 2)
            {
                if (input % 10 == answer[cnt]) // 스트라이크 확인
                {
                    answer[cnt] = 99;
                    ballRes[0]++;
                    cnt++;
                }
                else if (input % 10 == answer[ballCnt++])   // 볼 확인
                {
                    ballRes[1]++;
                    cnt++;
                    ballCnt = 0;
                }
                else if (ballCnt == TOTAL)    // 아웃 확인
                {
                    ballRes[2]++;
                    cnt++;
                    ballCnt = 0;
                } 
            }
            // 숫자 야구 결과 출력
            if (cnt > TOTAL - 1)
            {
                if (ballRes[0] == TOTAL)
                {
                    end = 1;
                }
                for (int i = 0; i < TOTAL; i++)
                {
                    answer[i] = answerTmp[i];
                    if (ballRes[i])
                    {
                        if (i == 0)
                        {
                            std::cout << ballRes[i] << " 스트라크! \n";
                        }
                        else if (i == 1)
                        {
                            std::cout << ballRes[i] << " 볼! \n";
                        }
                        else
                        {
                            std::cout << ballRes[i] << " 아웃! \n";
                        }
                        ballRes[i] = 0;
                    }
                }
                cnt++;
            }
            // 3스트라이크 시 종료
            if (end)
            {
                end = 0;
                std::cout << "=======================GAME END!====================== \n";
                break;
            }
        }
        
    }
    
    return 0;
}
// 빠른 리펙토링 쓴것
void PrintInfo()
{

}

int BoxArea(int w, int l)
{
    return w * l;
}

int BoxArea(int size)
{
    return size * size;
}
