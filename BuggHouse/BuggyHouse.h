#pragma once
#include "D2DFramework.h"
#include <memory>
#include <list>
#include "Bug.h"

// ������ ��ġ�� ���� 40������ �׸��ô�.
// �����̳� : �ƹ������� ����, ���� = list
    // ������ vs ����Ʈ ������
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

