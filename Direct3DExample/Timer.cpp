#include <Windows.h>		// window.h�� ����
#include "Timer.h"

namespace MyUtil
{
	Timer::Timer() :
		mdSecondsPerCount{ 0.0 },
		mdDeltaTime{ -1.0 },
		mfScale{ 1.0f },
		mllBaseTime{ 0 },
		mllPausedTime{ 0 },
		mllPrevTime{ 0 },
		mllCurrTime{ 0 },
		mllStopTime{ 0 },
		mbStopped{ false }
	{
		long long countsPerSec;
		QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
		mdSecondsPerCount = 1.0 / static_cast<double>(countsPerSec);

		// ���� : �ʴ� 60������ : 1/60
		// 1 ����ũ���� = �鸸���� 1�� = 0.0000001
	}

	void Timer::Start()
	{
		long long currTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

		mllBaseTime = currTime;
		mllPrevTime = currTime;
		mbStopped = false;
	}

	void Timer::Stop()
	{
		if (!mbStopped)
		{
			long long currTime;
			QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

			mllStopTime = currTime;
			mbStopped = true;
		}
	}

	void Timer::Resume()
	{
		long long currTime;
		QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

		if (mbStopped)
		{
			mllPausedTime += (currTime - mllStopTime);

			mllPrevTime = currTime;
			mllStopTime = 0;
			mbStopped = false;
		}
	}

	void Timer::Update()
	{
		if (mbStopped)
		{
			mdDeltaTime = 0.0f;
			return;
		}

		__int64 currTime;	// ����� ��Ʃ���(__�� �ٴ´�)
		QueryPerformanceCounter((LARGE_INTEGER*)&currTime);
		mllCurrTime = currTime;

		mdDeltaTime = (mllCurrTime - mllPrevTime) * mdSecondsPerCount;

		mllPrevTime = mllCurrTime;

		if (mdDeltaTime < 0.0)
		{
			mdDeltaTime = 0.0;
		}
	}

	float Timer::TotalTime() const
	{
		if (mbStopped)
		{
			return static_cast<float>(
				((mllStopTime - mllPausedTime) - mllBaseTime) * mdSecondsPerCount
				);
		}
		else
		{
			return static_cast<float>(
				((mllCurrTime - mllPausedTime) - mllBaseTime) * mdSecondsPerCount
				);
		}
	}

	float Timer::DeltaTime() const
	{
		return static_cast<float>(mdDeltaTime * mfScale);
	}

	void Timer::SetScale(float scale)
	{
		mfScale = scale;
	}

}
