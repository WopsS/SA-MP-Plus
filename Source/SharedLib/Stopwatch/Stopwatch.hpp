#pragma once

template<typename Clock = std::chrono::high_resolution_clock>
class Stopwatch
{
public:

	Stopwatch()
		: m_started(false)
		, m_start(Clock::now())
		, m_stop(Clock::now())
	{

	}

	~Stopwatch() = default;

	template<class ToDuration>
	const auto Elapsed() const
	{
		if (IsRunning() == true)
		{
			return std::chrono::duration_cast<ToDuration>(Clock::now() - m_start).count();
		}

		return std::chrono::duration_cast<ToDuration>(m_stop - m_start).count();
	}

	const bool IsRunning() const
	{
		return m_started;
	}

	void Reset()
	{
		m_started = false;
		m_start = Clock::now();
		m_stop = Clock::now();
	}

	void Restart()
	{
		m_started = true;
		m_start = Clock::now();
		m_stop = Clock::now();
	}

	void Start()
	{
		if (m_started == false)
		{
			m_start = Clock::now();
			m_started = true;
		}
	}

	void Stop()
	{
		if (m_started == true)
		{
			m_stop = Clock::now();
			m_started = false;
		}
	}

private:

	bool m_started;

	std::chrono::time_point<Clock> m_start;

	std::chrono::time_point<Clock> m_stop;
};