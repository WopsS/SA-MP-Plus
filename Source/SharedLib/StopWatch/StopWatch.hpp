#pragma once

template<typename Clock = std::chrono::high_resolution_clock>
class StopWatch
{
public:

	StopWatch()
		: m_started(false)
		, m_startClock(Clock::now())
		, m_stopClock(Clock::now())
	{

	}

	~StopWatch() = default;

	const bool IsRunning() const
	{
		return m_started;
	}

	template<class ToDuration>
	const auto Elapsed()
	{
		if (IsRunning() == true)
		{
			m_stopClock = Clock::now();
		}

		return std::chrono::duration_cast<ToDuration>(m_stopClock - m_startClock).count();
	}

	void Reset()
	{
		m_started = false;
		m_startClock = Clock::now();
		m_stopClock = Clock::now();
	}

	void Restart()
	{
		m_startClock = Clock::now();
		m_stopClock = Clock::now();
	}

	void Start()
	{
		if (m_started == false)
		{
			m_startClock = Clock::now();
			m_started = true;
		}
	}

	void Stop()
	{
		if (m_started == true)
		{
			m_stopClock = Clock::now();
			m_started = false;
		}
	}

private:

	bool m_started;

	std::chrono::time_point<Clock> m_startClock;

	std::chrono::time_point<Clock> m_stopClock;
};