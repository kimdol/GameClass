#pragma once

#include <cmath>
#include <cstdint>

namespace DX
{
	class StepTimer
	{
	private:
		LARGE_INTEGER m_qpcFrequency;
		LARGE_INTEGER m_qpcLastTime;
		uint64_t m_qpcMaxDelta;

		uint64_t m_elapsedTicks;
		uint64_t m_totalTicks;
		uint64_t m_leftOverTicks;

		uint64_t m_frameCount;
		uint64_t m_framesPerSecond;
		uint32_t m_framesThisSecond;
		uint64_t m_qpcSecondCounter;  // fps 표시하려고 하나 더 만듬
		
		bool m_isFixedTimesStep;
		uint64_t m_targetElapsedTicks;

	public:
		static const uint64_t TicksPerSecond = 10000000; // 특정한 값으로 고정
	
	public:
		StepTimer() noexcept(false) :	// 예외가 발생할수있다
			m_elapsedTicks{ 0 },
			m_totalTicks{ 0 },
			m_leftOverTicks{ 0 },
			m_frameCount{ 0 },
			m_framesPerSecond{ 0 },
			m_framesThisSecond{ 0 },
			m_qpcSecondCounter{ 0 },
			m_isFixedTimesStep{ false },
			m_targetElapsedTicks(TicksPerSecond / 60)
		{
			QueryPerformanceFrequency(&m_qpcFrequency);
			QueryPerformanceCounter(&m_qpcLastTime);
			m_qpcMaxDelta = static_cast<uint64_t>(m_qpcFrequency.QuadPart / 10);
		}
	};
}