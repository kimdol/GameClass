#pragma once
// 가정용 windows
// 기업 서버용 Wndows NT

// Windows7		0x0601
// Window8		0x0602
// Window8.1	0x0603
// Window10		0x0A00
#include <winsdkver.h>
#define _WIN32_WINNT 0x0A00	// OS 최대버전 설정(windows10 전용)

#include <winsdkver.h>

// 윈도우의 min(), max() 함수 제거 : c++에도 있기에 이름충돌방지
#define NOMINMAX
// GDI 기능 제거
#define NODRAWTEXT
#define NOGDI
#define NOBITMAP

// 모뎀 사용안함
#define NOMCX
// 서비스 기능 사용안함(윈도우 아이콘)
#define NOSERVICE
// 도움말 사용안함 - deprecated
#define NOHELP
// 마무리
#define WIN32_LEAN_AND_MEAN	// 필요없는거 제거

//----------------------------------------------------------------
// 자주 사용되는 헤더

#include <Windows.h>
#include <wrl/client.h>

#include <d3d11_1.h> // 버전 변경 가능
#include <dxgi1_6.h> // d3d 상위개념
#include <DirectXMath.h>
#include <DirectXColors.h>
// 조건부 컴파일
#ifdef _DEBUG	// 디버그 모드일때
#include <dxgidebug.h>
#endif
// c++ 라이브러리
#include <algorithm>
#include <exception>
#include <memory>
#include <stdexcept>
// c 
#include <stdio.h>

// direct TK
#pragma warning(push)
#pragma warning(disable:26812)	// 다른 사람코드 경고무시

#include "Audio.h"	// 효과음
#include "CommonStates.h"	// near하게, pointer하게..
#include "WICTextureLoader.h" // WIC를 이용해서 Texture를 만듬
#include "Effects.h"
#include "GamePad.h"
#include "GeometricPrimitive.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Model.h"
#include "PrimitiveBatch.h"
#include "SimpleMath.h"
#include "SpriteBatch.h"
#include "SpriteFont.h"
#include "VertexTypes.h"

#pragma warning(pop)

#include "StepTimer.h"

namespace DX
{
	class com_exception : public std::exception
	{
	public:
		HRESULT result;

	public:
		com_exception(HRESULT hr) noexcept : result{ hr } {}

		const char* what() const override
		{
			static char s_str[65]{};

			sprintf_s(
				s_str,
				"Failure with HRESULT %08x",
				static_cast<unsigned int>(result)
			);

			return s_str;
		}
	};

	inline void ThrowIfFailed(HRESULT hr)
	{
		if (FAILED(hr))
		{
			throw com_exception(hr);
		}
	}
}
