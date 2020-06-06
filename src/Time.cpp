#include "Time.h"
#include <windows.h>

Time::Time()
	: m_DeltaTime(0)
	, m_SecondsPerCount(0)
	, m_TotalTime(0)
	, m_PrevTime(0)
{
	long long countsPerSec;
	QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
	m_SecondsPerCount = 1.0 / (double)countsPerSec;
}

Time::~Time()
{
}

inline const double Time::GetTotalTime() const
{
	return m_TotalTime;
}

void Time::Reset()
{
}

void Time::Start()
{
}

void Time::Stop()
{

}

void Time::Update()
{
	long long currTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&currTime);

	m_DeltaTime = (currTime - m_PrevTime) *m_SecondsPerCount;

	m_PrevTime = currTime;

	m_DeltaTime = (m_DeltaTime < 0) ? 0 : m_DeltaTime;
}

