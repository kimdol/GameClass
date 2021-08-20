#include <iostream>

int main()
{
    //int input[6]{};
    //std::cout << "숫자 5개를 입력하세요 : ";
    //for (int i = 0; i < 5; i++)
    //{
    //    std::cin >> input[i];
   //     input[5] += input[i];
  //  }

  //  std::cout << input[5] << std::endl;
    

    /*std::cout << ((input == 'a' || input == 'e' || input == 'i' || input == 'o' || input == 'u') ?
        "모음입니다."
        : "모음이 아닙니다.")
        << std::endl;*/

        // std::cout << input << "은 " << ((input >= 10 && input < 20) ? "10이상, 20미만인 수입니다." : "10이상, 20미만인 수가 아닙니다") << std::endl;


    /*for (int i = 0; i <= 50; i++)
    {
        if (i % 3 == 0 || i % 7 == 0)
        {
            std::cout << i << " ";
        }
    }*/

    /*int arr[4]{ 2, 4, 6, 8 };

    for (int i = 0; i < 4; i++)
    {
        std::cout << arr[i] << " ";
    }*/

    /*“Hello World” 라는 메시지를 출력하는 함수를 만들어 보세요.*/
    std::cout << "Hello World" << std::endl;
    /*두 정수 a, b 를 매개변수로 받아서, a를 b로 나눈 나머지를 반환하는 함수를 만들어 보세요. */
    /*int a, b;
    std::cin >> a >> b;
    std::cout << a % b << std::endl;*/
    /*myNumber와 myCharacter의 주소를 출력해 보세요.*/
    /*int myNumber{ 10 };
    char myCharacter{ 'a' };

    int* a{ &myNumber };
    char* b{ &myCharacter };

    std::cout << &myNumber << " " << (void*)&myCharacter << std::endl
        << a << " " << (void*)b << std::endl
        << *a << " " << *b << std::endl;*/
    /*다음 캐릭터 데이터를 구조체로 선언해 보세요.*/
    struct character
    {
        int hp;
        int ad;
        float speed;
    };
    /*다음과 같은 변수를 선언 및 정의하세요.
    플레이어
    체력 : 100
    공격력 : 10
    이동속도 : 10.0*/

    character player{ 100, 10, 10.0f };
    character* pPlayer{ &player };

    /*위 변수의 멤버를 모두 화면에 출력해 보세요.*/
    /*std::cout << player.hp << " "
        << player.ad << " "
        << player.speed << " "
        << pPlayer->hp << " "
        << pPlayer->ad << " "
        << pPlayer->speed << " "
        << std::endl;*/
    /*동적할당*/
    int* a{ new int };
    character* pPlayer2{ new character };

    pPlayer2->hp = 100;
    pPlayer2->ad = 10;
    pPlayer2->speed = 10.0f;

    std::cout << pPlayer2->hp << " "
        << pPlayer2->ad << " "
        << pPlayer2->speed << " "
        << std::endl; 
    
    delete pPlayer2;

    *a = 10;
    std::cout << *a << std::endl;

    delete a;



        

    
}
