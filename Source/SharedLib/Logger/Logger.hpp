#pragma once

#include <Logger/Record.hpp>

class Logger : public Singleton<Logger>
{
public:

	void operator+=(Log::Record& rhs);

private:

	friend class Singleton<Logger>;

	Logger(const std::string& Path = "samp_plus.log", bool IsServer = true);
	~Logger();

	std::fstream m_file;

	bool m_shouldCout;

	bool m_isServer;
};

#define LOG(level) *(Logger::GetInstance()) += Log::Record(level)

#define LOG_VERBOSE LOG(Log::Level::Verbose)
#define LOG_DEBUG LOG(Log::Level::Debug)
#define LOG_INFO LOG(Log::Level::Info)
#define LOG_WARNING LOG(Log::Level::Warning)
#define LOG_ERROR LOG(Log::Level::Error)

#define LOG_EMPTY LOG_INFO << ""