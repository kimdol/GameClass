#include <iostream>

int main()
{
    // 초기화 = 선언 + 정의
    // 배정문 = 대입문 = x = 1; = 식으로도 부를 수 있음
    // Camel 표기법 = 시작은 소문자 그 다음은 대문자(앞으로 사용함 변수만)
    // 파스칼 표기법 = 앞으로 함수이름지을때만
    //유니폼 초기화 = int x{0}; 이다 최근 c++에서 나옴
    // L-Value = 연산자(+, =...)기준으로 왼쪽을 말함

    // unsigned long int까지 써도 됨
    char myChar;
    // myChar = '''; '를 출력할 수 없다.

    // 특수한 목적
    // Escape Sequence (아스키 코드에 없는 것 즉, \를 앞에 붙이면 됨)

    myChar = '\'';
    std::cout << myChar;

    // \0 : 문자열의 끝을 의미(NULL)
    // \t : TAP 키
    // \v : 세로로 가는 Tap키
    // \r : Carriage Return(줄의 처음으로 ㄱㄱ)
    // \n : New Line

    // 실제로 프로그램이 실행이 될 때 엔터는 "\r\n"이 입력된거와 같다.

    std::cout << "Hello" << std::endl; // std::cout << "Hello\r\n"; 와 같다 또 window 환경에서 그냥 \n과 같다.

    // #은 비쥬얼 스튜디오에게 지시하는 것이다.

    const double pi{ 3.1415 }; // const는 프로그래밍의 편의성을 위해서이다. <= 대도록이면 이걸 사용
    // #define은 컴파일러가 일하기 때문에 컴파일에 따라 일을 안할 수도 있다. <= 유니티 아래와 같이 쓸 때 사용
    // #ifdef IOS
            // 애플
    // #else
            // 안드로이드
    // endif

    // 이름, 나이를 입력받아서 출력하라.

    std::string name;
    unsigned int age;   // -1을 입력못하게 막음의 방법 1(첫번째 방법) 
    // 언더플로우로 큰 숫자가 나오는데 이걸 if으로 막으면 된다.

    std::cout << "이름과 나이를 입력하고 엔터를 눌러주세요\n";

    std::cin >> name >> age;    // 공백이 만날 때 까지만 읽음 탭도 됨(공백문자 White Space)

    
    std::cout << "Hello, " << name <<
        "(" << age << ")" << std::endl;

   


}
