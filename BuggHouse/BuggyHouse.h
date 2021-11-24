#pragma once
#include "D2DFramework.h"
#include <memory>
#include <list>
#include "Bug.h"

// 임의의 위치에 벌레 40마리를 그립시다.
// 컨테이너 : 아무곳에서 삭제, 삽입 = list
    // 포인터 vs 스마트 포인터
    // Actor <- Bug

class BuggyHouse :
    public D2DFramework
{
    std::unique_ptr<Actor> mspBackground;
    std::list<std::unique_ptr<Bug>> mBugList;

public:
    virtual HRESULT Initialize(
        HINSTANCE hInstance, LPCWSTR title = L"Buggy House",
        UINT width = 1024, UINT height = 768
    ) override;
    virtual void Release() override;
    virtual void Render() override;
};

