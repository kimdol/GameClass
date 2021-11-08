// Windows API 헤더
#include <Windows.h>

// entry point
int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd
	)
{
	/*첫 시작*/
	// MessageBox(nullptr, L"HelloWorld", L"SimpleWindow", MB_ICONEXCLAMATION | MB_OK);
	
	/* 윈도우를 만들기 위한 4단계 */
	// 1. 윈도우 클래스 등록 - 윈도우 프로시져 등록
	// 2. 윈도우 생성 - (1)번의 클래스 지정
	// 3. 윈도우 메시지(이벤트) 루프
	// ----------------------------------------
	// * 윈도우 프로시져 함수 만들기 - callback

	return 0;
}