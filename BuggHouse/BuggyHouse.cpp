#include "BuggyHouse.h"

HRESULT BuggyHouse::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
    HRESULT hr = D2DFramework::Initialize(hInstance, title, width, height);
    ThrowIfFailed(hr, "Failed D2DFramework::Initialize() Failed");

    mspBackground = std::make_unique<Actor>(
        this,
        L"Data/back1_1024.png",
        0.0f, 0.0f
        );

    int x, y;
    RECT rct;
    GetClientRect(mHwnd, &rct);
    for (int i = 0; i < 40; i++)
    {
        mBugList.push_back(std::make_unique<Bug>(this));
    }

    return S_OK;
}

void BuggyHouse::Release()
{
    for (auto& bug : mBugList)
    {
        bug.reset();
    }
    mBugList.clear();
    mspBackground.reset();
    D2DFramework::Release();
}

void BuggyHouse::Render()
{
    HRESULT hr;
    mspRenderTarget->BeginDraw();


    mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));
    mspRenderTarget->SetTransform(D2D1::Matrix3x2F::Identity()); // 원점

    CheckBugs();

    mspBackground->Draw();
    for (auto& bug : mBugList)
    {
        bug->Draw();
    }
   
    hr = mspRenderTarget->EndDraw();
    if (hr == D2DERR_RECREATE_TARGET)
    {
        CreateDeviceResources();
    }
}

void BuggyHouse::CheckBugs()
{
    if (GetAsyncKeyState(VK_LBUTTON) & 0x08000)
    {
        POINT pt;
        GetCursorPos(&pt); // 스크린 좌표
        ScreenToClient(mHwnd, &pt);

        auto it = std::remove_if(mBugList.begin(), mBugList.end(),
            [&](auto& actor)
            {
                return actor->IsClicked(pt);
            }
        );
        mBugList.erase(it, mBugList.end());
    }
}
