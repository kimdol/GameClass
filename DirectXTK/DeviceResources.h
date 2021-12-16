#pragma once
/*윈도우크기, 디바이스 로스에 관련된 리소스를 모아놓음*/
namespace DX
{
	interface IDeviceNotify
	{
		virtual void OnDeviceLost() = 0;
		virtual void OnDeviceRestored() = 0;

	protected:
		~IDeviceNotify() = default;
	};

	class DeviceResources
	{
	private:
		Microsoft::WRL::ComPtr<IDXGIFactory2>			m_dxgiFactory;
		Microsoft::WRL::ComPtr<ID3D11Device1>			m_d3dDevice;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext1>	m_d3dContext;
		Microsoft::WRL::ComPtr<IDXGISwapChain1>			m_swapChain;
		// 그래픽카드 디버그 주석
		Microsoft::WRL::ComPtr<ID3DUserDefinedAnnotation> m_d3dAnnotation;
		
		Microsoft::WRL::ComPtr<ID3D11Texture2D>			m_renderTarget;
		Microsoft::WRL::ComPtr<ID3D11Texture2D>			m_depthStencil;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView>	m_d3dRenderTargetView;
		Microsoft::WRL::ComPtr<ID3D10DepthStencilView>	m_d3dDepthStencilView;

		D3D11_VIEWPORT			m_screenViewport;
		DXGI_FORMAT				m_backBufferFormat;
		DXGI_FORMAT				m_depthBufferFormat;
		UINT					m_backBufferCount;

		HWND					m_window;
		D3D_FEATURE_LEVEL		m_d3dFeatureLevel;
		RECT					m_outputSize;

		DXGI_COLOR_SPACE_TYPE	m_colorSpace;
		unsigned				m_options;

		IDeviceNotify*			m_deviceNotify;
	};
}


