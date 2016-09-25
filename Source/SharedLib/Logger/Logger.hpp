#pragma once

#include <Logger/Record.hpp>

namespace SharedLib
{
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
}

#define LOG(level) *(SharedLib::Logger::GetInstance()) += SharedLib::Log::Record(level)

#define LOG_VERBOSE LOG(SharedLib::Log::Level::Verbose)
#define LOG_DEBUG LOG(SharedLib::Log::Level::Debug)
#define LOG_INFO LOG(SharedLib::Log::Level::Info)
#define LOG_WARNING LOG(SharedLib::Log::Level::Warning)
#define LOG_ERROR LOG(SharedLib::Log::Level::Error)

#define LOG_EMPTY LOG_INFO << ""