#include "pch.h"
#include "Game.h"
#include <sstream>
#include <iomanip>

using Microsoft::WRL::ComPtr;
using namespace DirectX;
using namespace DirectX::SimpleMath;

// 어느 플랫폼이든지 돌아가게끔함
extern void ExitGame() noexcept;

Game::Game() noexcept(false)
{
	m_deviceResources = std::make_unique<DX::DeviceResources>();
	m_deviceResources->RegisterDeviceNotify(this);

	m_currentFrame = 0;
	m_timeToNextFrame = 0.1f;
}

Game::~Game()
{
}

void Game::Initialize(HWND window, int width, int height)
{
	m_keyboard = std::make_unique<Keyboard>();
	m_mouse = std::make_unique<Mouse>();

	m_mouse->SetWindow(window);

	m_deviceResources->SetWindow(window, width, height);

	m_deviceResources->CreateDeviceResources();
	CreateDeviceDependentResources();

	m_deviceResources->CreateWindowSizeDependentResources();
	CreateWindowSizeDependentResources();
}
#pragma region Frame Update

void Game::Tick()
{
	m_timer.Tick([&]()
		{
			Update(m_timer);
		}
	);

	Render();
}

void Game::Update(DX::StepTimer const& timer)
{
	auto kb = m_keyboard->GetState();
	if (kb.Escape)
	{
		ExitGame();
	}

	m_timeToNextFrame -= timer.GetElapsedSeconds();
	if (m_timeToNextFrame < 0.0f)
	{
		m_timeToNextFrame = 0.1f;
		m_currentFrame = (m_currentFrame + 1) % static_cast<int>(m_textures.size());
	}
}

#pragma endregion

#pragma region Message Handlers

void Game::OnActivated()
{
}

void Game::OnDeActivated()
{
}

void Game::OnSuspending()
{
}

void Game::OnResuming()
{
	m_timer.ResetElapsedTime();
}

void Game::OnWindowMoved()
{
	auto r = m_deviceResources->GetOutputSize();
	m_deviceResources->WindowSizeChanged(r.right, r.bottom);
}

void Game::OnWindowSizeChanged(int width, int height)
{
	if (!m_deviceResources->WindowSizeChanged(width, height))
	{
		return;
	}

	CreateWindowSizeDependentResources();
}

void Game::GetDefaultSize(int& width, int& height) const noexcept
{
	width = 800;
	height = 600;
}

#pragma endregion

#pragma region Frame Render

void Game::Render()
{
	// 겁나게 빠를 때 update 건너뛰기 방지용 코드
	if (m_timer.GetFrameCount() == 0)
	{
		return;
	}

	Clear();

	m_deviceResources->PIXBeginEvent(L"Render");

	// Draw
	m_spriteBatch->Begin(SpriteSortMode_Deferred, m_commonStates->NonPremultiplied());

	m_spriteBatch->Draw(
		m_textures[m_currentFrame].Get(),
		XMFLOAT2(0, 0)
	);

	m_spriteBatch->End();
	// Draw End

	m_deviceResources->PIXEndEvent();

	m_deviceResources->Present();
}
// 백버퍼 지우기
void Game::Clear()
{
	m_deviceResources->PIXBeginEvent(L"Clear");

	auto context = m_deviceResources->GetD3DDeviceContext();
	auto renderTarget = m_deviceResources->GetRenderTargetView();
	auto depthStencil = m_deviceResources->GetDepthStencilView();

	context->ClearRenderTargetView(renderTarget, Colors::CornflowerBlue);
	context->ClearDepthStencilView(depthStencil, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
	// 랜더타겟 초기화
	context->OMSetRenderTargets(1, &renderTarget, depthStencil);
	auto viewport = m_deviceResources->GetScreenViewport();
	context->RSSetViewports(1, &viewport);

	m_deviceResources->PIXEndEvent();
}

#pragma endregion

#pragma region Direct3D Resources
void Game::CreateDeviceDependentResources()
{
	auto device = m_deviceResources->GetD3DDevice();
	auto context = m_deviceResources->GetD3DDeviceContext();

	m_commonStates = std::make_unique<CommonStates>(device);
	m_spriteBatch = std::make_unique<SpriteBatch>(context);

	std::wstringstream fileName;
	for (int i = 0; i < 10; i++)
	{
		fileName.str(L"");
		fileName << L"Assets/die" << std::setfill(L'0') << 
			std::setw(2) << i + 1 << L".png";

		DX::ThrowIfFailed(CreateWICTextureFromFile(
			device,
			fileName.str().c_str(),
			nullptr,
			m_textures[i].ReleaseAndGetAddressOf()
		));
	}
}

void Game::CreateWindowSizeDependentResources()
{
}

void Game::OnDeviceLost()
{
	for (auto& tex : m_textures)
	{
		tex.Reset();
	}
	m_spriteBatch.reset();
	m_commonStates.reset();
}

void Game::OnDeviceRestored()
{
	CreateDeviceDependentResources();
	CreateWindowSizeDependentResources();
}
#pragma endregion
