#pragma once

class Time
{
public:
	Time();
	~Time();

	inline const double Time::GetDeltaTime() const
	{
		return m_DeltaTime;
	}

	inline const double GetTotalTime() const ;

	void Reset();
	void Start();
	void Stop();
	void Update();

private:
	double m_DeltaTime;
	double m_SecondsPerCount;
	double m_TotalTime;
	
	long long m_PrevTime;
};