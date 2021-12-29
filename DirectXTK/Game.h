#pragma once
#include <vector>

#include <fstream>
#include <sstream>

#include "DeviceResources.h"
#include "StepTimer.h"

#pragma warning(push)
#pragma warning(disable:26812)
#pragma warning(disable:26451)
#pragma warning(disable:26495)
#pragma warning(disable:6319)
#pragma warning(disable:6386)
#pragma warning(disable:6385)
#include "rapidjson//document.h"
#pragma warning(pop)

class Game final :
    public DX::IDeviceNotify
{
private:
    std::unique_ptr<DX::DeviceResources>    m_deviceResources; // has a관계
    DX::StepTimer                           m_timer;
    std::unique_ptr<DirectX::Keyboard>      m_keyboard;
    std::unique_ptr<DirectX::Mouse>         m_mouse;

    std::unique_ptr<DirectX::SpriteBatch>       m_spriteBatch;
    std::unique_ptr<DirectX::CommonStates>      m_commonStates;

    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> m_texture;

    int m_currentFrame;
    double m_timeToNextFrame;

    std::vector<RECT> m_rects;


public:
    Game() noexcept(false);
    ~Game();
    // 메모리를 전부다 스마트포인터로 쓴다는 뜻
    Game(Game&&) = default;
    Game& operator=(Game&&) = default;

    Game(Game const&) = delete;
    Game& operator=(Game const&) = delete;

    void Initialize(HWND window, int width, int height);

    void Tick();

    void OnDeviceLost() override;
    void OnDeviceRestored() override;

    void OnActivated();
    void OnDeActivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowMoved();
    void OnWindowSizeChanged(int width, int height);

    void GetDefaultSize(int& width, int& height) const noexcept;

private:
    void LoadSpriteSheetFromJSON();

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();

    void CreateDeviceDependentResources();
    void CreateWindowSizeDependentResources();

};

