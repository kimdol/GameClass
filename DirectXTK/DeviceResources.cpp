#include "pch.h"
#include "DeviceResources.h"

using namespace DirectX;
using namespace DX;
using Microsoft::WRL::ComPtr;

#ifdef __clang__	// 컴파일러
#pragma clang diagnostic ignored "-Wcovered-switch-default"
#pragma clang diagnostic ignored "-Wswitch-enum"
#endif

#pragma warning(disable : 4061)

namespace
{
#if defined(_DEBUG)
	inline bool SdkLayersAvailable() noexcept
	{
		HRESULT hr = D3D11CreateDevice(
			nullptr,
			D3D_DRIVER_TYPE_NULL,
			nullptr,
			D3D11_CREATE_DEVICE_DEBUG,
			nullptr,
			0,
			D3D11_SDK_VERSION,
			nullptr,
			nullptr,
			nullptr
		);

		return SUCCEEDED(hr);
	}
#endif

	inline DXGI_FORMAT NoSRGB(DXGI_FORMAT fmt) noexcept
	{
		switch(fmt)
		{
			case DXGI_FORMAT_R8G8B8A8_UNORM_SRGB:
				return DXGI_FORMAT_R8G8B8A8_UNORM;
			case DXGI_FORMAT_B8G8R8A8_UNORM_SRGB:
				return DXGI_FORMAT_B8G8R8A8_UNORM;
			case DXGI_FORMAT_B8G8R8X8_UNORM_SRGB:
				return DXGI_FORMAT_B8G8R8X8_UNORM;
			default:
				return fmt;
		}
	}
}

void DeviceResources::CreateFactory()
{
	
}

void DeviceResources::GetHardwareAdapter(IDXGIAdapter1** ppAdapter)
{
}

void DeviceResources::UpdateColorSpace()
{
}

DeviceResources::DeviceResources(
	DXGI_FORMAT backBufferFormat, 
	DXGI_FORMAT depthBufferFormat, 
	UINT backBufferCount, 
	D3D_FEATURE_LEVEL minFeatureLevel, 
	unsigned int flags
) noexcept :
	m_screenViewport{}, 
	m_backBufferFormat{ backBufferFormat },
	m_depthBufferFormat{ depthBufferFormat },
	m_backBufferCount{ backBufferCount },
	m_d3dMinFeatureLevel{ minFeatureLevel },
	m_window{ nullptr },
	m_d3dFeatureLevel{ D3D_FEATURE_LEVEL_9_1 },
	m_outputSize{ 0, 0, 1, 1 },
	m_colorSpace{ DXGI_COLOR_SPACE_RGB_FULL_G22_NONE_P709 },
	m_options{ flags | c_FlipPresent },
	m_deviceNotify{ nullptr }
{

}
// 참고로 유니티, 언리얼이 다해줌
void DeviceResources::CreateDeviceResources()
{
	UINT creationFlag = D3D11_CREATE_DEVICE_BGRA_SUPPORT;

#if defined(_DEBUG)
	if (SdkLayersAvailable())
	{
		creationFlag |= D3D11_CREATE_DEVICE_DEBUG;
	}
	else
	{
		OutputDebugStringA("WARNING : Direct3D Debuge Device is not available!\n");
	}
#endif

	CreateFactory();

	// 가변 갱신률
	if (m_options & c_AllowTearing)	// FPS하는 애들은 모니터가 높은 사양이다.
	{
		BOOL allowTearing = FALSE;

		ComPtr<IDXGIFactory5> factory5;
		HRESULT hr = m_dxgiFactory.As(&factory5);	// 다형성
		if (SUCCEEDED(hr))
		{
			hr = factory5->CheckFeatureSupport(
				DXGI_FEATURE_PRESENT_ALLOW_TEARING,
				&allowTearing,
				sizeof(allowTearing)
			);
		}

		if (FAILED(hr) || !allowTearing)
		{
			m_options &= ~c_AllowTearing;
#ifdef _DEBUG
			OutputDebugStringA("WARNING: VBR(Varable Refresh Rate not Supported)\n");
#endif 
		}
	}

	// HDR
	if (m_options & c_EnableHDR)
	{
		ComPtr<IDXGIFactory5> factory5;
		if (FAILED(m_dxgiFactory.As(&factory5)))
		{
			m_options &= ~c_EnableHDR;
#ifdef _DEBUG
			OutputDebugStringA("WARNING: HDR not Supported!\n");
#endif 
		}
	}

	// FLIP
	if (m_options & c_FlipPresent)
	{
		ComPtr<IDXGIFactory4> factory4;
		if (FAILED(m_dxgiFactory.As(&factory4)))
		{
			m_options &= ~c_FlipPresent;
#ifdef _DEBUG
			OutputDebugStringA("WARNING: FLIP Present not Supported!\n");
#endif 
		}
	}

	static const D3D_FEATURE_LEVEL s_featureLevels[]{
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3,
		D3D_FEATURE_LEVEL_9_2,
		D3D_FEATURE_LEVEL_9_1
	};

	UINT featLevelCount{ 0 };
	for (; featLevelCount < _countof(s_featureLevels); ++featLevelCount)
	{
		if (s_featureLevels[featLevelCount] < m_d3dMinFeatureLevel)
		{
			break;
		}
	}

	if (!featLevelCount)
	{
		throw std::out_of_range("Min Feature Level is too high");
	}

	// 이제 드디어 디바이스 만들기
	ComPtr<IDXGIAdapter1> adapter;
	GetHardwareAdapter(adapter.GetAddressOf());

	ComPtr<ID3D11Device> device;
	ComPtr<ID3D11DeviceContext> context;

	HRESULT hr = E_FAIL;
	if (adapter)
	{
		hr = D3D11CreateDevice(
			adapter.Get(),
			D3D_DRIVER_TYPE_UNKNOWN,
			nullptr,
			creationFlag,
			s_featureLevels,
			featLevelCount,
			D3D11_SDK_VERSION,
			device.GetAddressOf(),
			&m_d3dFeatureLevel,
			context.GetAddressOf()
		);
	}
#if defined(NDEBUG)
	else
	{
		throw std::exception("No Direct3D hardware device found");
	}
#else
	// 소프트웨어 랜더러
	if (FAILED(hr))
	{
		hr = D3D11CreateDevice(
			nullptr,
			D3D_DRIVER_TYPE_WARP,
			nullptr,
			creationFlag,
			s_featureLevels,
			featLevelCount,
			D3D11_SDK_VERSION,
			device.GetAddressOf(),
			&m_d3dFeatureLevel,
			context.GetAddressOf()
		);

		if (SUCCEEDED(hr))
		{
			OutputDebugStringA("Direct3D Adapter - WARP\n");
		}
	}
#endif

	ThrowIfFailed(hr);

#ifndef NDEBUG
	ComPtr<ID3D11Debug> d3dDebug;
	if (SUCCEEDED(device.As(&d3dDebug)))
	{
		ComPtr<ID3D11InfoQueue> d3dInfoQueue;
		if (SUCCEEDED(d3dDebug.As(&d3dInfoQueue)))
		{
#ifdef _DEBUG
			d3dInfoQueue->SetBreakOnSeverity(D3D11_MESSAGE_SEVERITY_CORRUPTION, true);
			d3dInfoQueue->SetBreakOnSeverity(D3D11_MESSAGE_SEVERITY_ERROR, true);
#endif
			D3D11_MESSAGE_ID hide[]{
				D3D11_MESSAGE_ID_SETPRIVATEDATA_CHANGINGPARAMS,
			};
			D3D11_INFO_QUEUE_FILTER filter{};
			filter.DenyList.NumIDs = _countof(hide);
			filter.DenyList.pIDList = hide;
			d3dInfoQueue->AddStorageFilterEntries(&filter);
		}
	}
#endif

	ThrowIfFailed(device.As(&m_d3dDevice));
	ThrowIfFailed(context.As(&m_d3dContext));
	ThrowIfFailed(context.As(&m_d3dAnnotation));
}

void DeviceResources::CreateWindowSizeDependentResources()
{
	if (!m_window)
	{
		throw std::exception("SetWindow() shuld be called with Win32 Handle!");
	}

	ID3D11RenderTargetView* nullViews[]{ nullptr };
	m_d3dContext->OMSetRenderTargets(_countof(nullViews), nullViews, nullptr);
	m_d3dRenderTargetView.Reset();
	m_d3dDepthStencilView.Reset();
	m_renderTarget.Reset();
	m_depthStencil.Reset();

	m_d3dContext->Flush();

	const UINT backBufferWidth = std::max<UINT>(
		static_cast<UINT>(m_outputSize.right - m_outputSize.left),
		1u
	);
	const UINT backBufferHeight = std::max<UINT>(
		static_cast<UINT>(m_outputSize.bottom - m_outputSize.top),
		1u
	);
	const DXGI_FORMAT backBufferFormat{
		(m_options & (c_FlipPresent | c_AllowTearing | c_EnableHDR)) ?
		NoSRGB(m_backBufferFormat) : m_backBufferFormat
	};

	if (m_swapChain)
	{
		HRESULT hr = m_swapChain->ResizeBuffers(
			m_backBufferCount,
			backBufferWidth,
			backBufferHeight,
			backBufferFormat,
			(m_options & c_AllowTearing) ? DXGI_SWAP_CHAIN_FLAG_ALLOW_TEARING : 0u
		);

		if (hr == DXGI_ERROR_DEVICE_REMOVED || hr == DXGI_ERROR_DEVICE_RESET)
		{
#ifdef _DEBUG
			char buf[64]{};
			sprintf_s(buf, "Device Lost on ResizeBuffers(): code 0x%08X\n",
				static_cast<unsigned int>
				(
					(hr == DXGI_ERROR_DEVICE_REMOVED) ?
					m_d3dDevice->GetDeviceRemovedReason() :
					hr
				)
			);
			OutputDebugStringA(buf);
#endif
			HandleDeviceLost();
			return;
		}
		else
		{
			ThrowIfFailed(hr);
		}
	}
	else
	{

	}
}

void DeviceResources::SetWindow(HWND window, int width, int height) noexcept
{
}

bool DeviceResources::WindowSizeChanged(int width, int height)
{
	return false;
}

void DeviceResources::HandleDeviceLost()
{
}

void DeviceResources::Present()
{
}
