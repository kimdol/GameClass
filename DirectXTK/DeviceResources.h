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
		unsigned int			m_options;	// 32개만듬

		IDeviceNotify*			m_deviceNotify;

	public:
		static const unsigned int c_FlipPresent = 0x01;
		static const unsigned int c_AllowTearing = 0x2;
		static const unsigned int c_EnableHDR = 0x04;

	private:
		void CreateFactory();
		void GetHardwareAdapter(IDXGIAdapter1** ppAdapter);
		void UpdateColorSpace();

	public:
		DeviceResources();
		~DeviceResources() = default;	// 숨기는 이유는 스마트 포인터를 쓰겠다는 뜻
	
		DeviceResources(DeviceResources&&) = default;	// 이동생성자
		DeviceResources& operator = (DeviceResources&&) = default; // 이동대입연산자
	
		DeviceResources(const DeviceResources&) = delete;
		DeviceResources& operator = (const DeviceResources&) = delete;

	public:
		void CreateDeviceResources();
		void CreateWindowSizeDependentResources();
		void SetWindow(HWND window, int width, int height) noexcept;
		bool WindowSizeChanged(int width, int height);
		void HandleDeviceLost();
		void RegisterDeviceNotify(IDeviceNotify* deviceNotify) noexcept
		{
			m_deviceNotify = deviceNotify;
		}
		void Present(); // 그리기

	public:
		RECT GetOutputSize() const noexcept { return m_outputSize; }
		auto GetD3DDevice() const noexcept { return m_d3dDevice.Get(); }
		auto GetD3DDeviceContext() const noexcept { return m_d3dContext.Get(); }
		auto GetDXGIFactory() const noexcept { return m_dxgiFactory.Get(); }
		auto GetWindow() const noexcept { return m_window; }
		auto GetDeviceFeatureLevel() const noexcept { return m_d3dFeatureLevel; }
		auto GetRenderTarget() const noexcept { return m_renderTarget.Get(); }
		auto GetDepthStencil() const noexcept { return m_depthStencil.Get(); }
		auto GetRenderTargetView() const noexcept { return m_d3dRenderTargetView.Get(); }
		auto GetDepthStencilView() const noexcept { return m_d3dDepthStencilView.Get(); }
		auto GetBackBufferFormat() const noexcept { return m_backBufferFormat; }
		auto GetDepthBufferFormat() const noexcept { return m_depthBufferFormat; }
		auto GetScreenViewport() const noexcept { return m_screenViewport; }
		auto GetColorSpace() const noexcept { return m_colorSpace; }
		auto GetDeviceOptions() const noexcept { return m_options; }

	public:
		void PIXBeginEvent(_In_z_ const wchar_t* name)
		{
			m_d3dAnnotation->BeginEvent(name);
		}
		void PIXEndEvent()
		{
			m_d3dAnnotation->EndEvent();
		}
		void PIXSetMarker(_In_z_ const wchar_t* name)
		{
			m_d3dAnnotation->SetMarker(name);
		}
	};
}


