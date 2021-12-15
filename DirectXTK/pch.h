#pragma once
// ������ windows
// ��� ������ Wndows NT

// Windows7		0x0601
// Window8		0x0602
// Window8.1	0x0603
// Window10		0x0A00
#include <winsdkver.h>
#define _WIN32_WINNT 0x0A00	// OS �ִ���� ����(windows10 ����)

#include <winsdkver.h>

// �������� min(), max() �Լ� ���� : c++���� �ֱ⿡ �̸��浹����
#define NOMINMAX
// GDI ��� ����
#define NODRAWTEXT
#define NOGDI
#define NOBITMAP

// �� ������
#define NOMCX
// ���� ��� ������(������ ������)
#define NOSERVICE
// ���� ������ - deprecated
#define NOHELP
// ������
#define WIN32_LEAN_AND_MEAN	// �ʿ���°� ����

//----------------------------------------------------------------
// ���� ���Ǵ� ���

#include <Windows.h>
#include <wrl/client.h>

#include <d3d11_1.h> // ���� ���� ����
#include <dxgi1_6.h> // d3d ��������
#include <DirectXMath.h>
#include <DirectXColors.h>
// ���Ǻ� ������
#ifdef _DEBUG	// ����� ����϶�
#include <dxgidebug.h>
#endif
// c++ ���̺귯��
#include <algorithm>
#include <exception>
#include <memory>
#include <stdexcept>
// c 
#include <stdio.h>

// direct TK
#pragma warning(push)
#pragma warning(disable:26812)	// �ٸ� ����ڵ� �����

#include "Audio.h"	// ȿ����
#include "CommonStates.h"	// near�ϰ�, pointer�ϰ�..
#include "WICTextureLoader.h" // WIC�� �̿��ؼ� Texture�� ����
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
