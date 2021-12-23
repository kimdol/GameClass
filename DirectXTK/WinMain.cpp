#include "pch.h"
#include "Game.h"

using namespace DirectX;

namespace
{
	std::unique_ptr<Game> g_game;
}

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
// c���� �����ϵǰԲ� ��
extern "C"
{
	__declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
	__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}

int WINAPI WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	if (!XMVerifyCPUSupport())
	{
		return 1;
	}

	HRESULT hr = CoInitializeEx(nullptr, COINITBASE_MULTITHREADED);
	if (FAILED(hr))
	{
		return 1;
	}

	g_game = std::make_unique<Game>();


	CoUninitialize();

	return 0;
}