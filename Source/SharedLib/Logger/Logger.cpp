#include <SharedLib.hpp>
#include <Logger/Logger.hpp>

SharedLib::Logger::Logger(const std::string& Path, const bool IsServer)
	: m_shouldCout(false)
	, m_isServer(IsServer)
{
	m_file.open(Path, IsServer == true ? std::ios::app : std::ios::out);
	m_file.seekg(0, std::ios::end);

	if (m_file.tellg() > 0)
	{
		(*this).operator+=(Log::Record(Log::Level::Info) << std::endl);
		(*this).operator+=(Log::Record(Log::Level::Info) << "----------------------");
	}

	(*this).operator+=(Log::Record(Log::Level::Info) << "SA-MP+ " << (IsServer == true ? "Server" : "Client"));
	(*this).operator+=(Log::Record(Log::Level::Info) << "----------------------");

	m_shouldCout = true;
}

SharedLib::Logger::~Logger()
{
	m_file.close();
}

void SharedLib::Logger::operator+=(Log::Record& rhs)
{
	m_file << rhs.Get(false) << std::endl;
	m_file.flush();

	if (m_shouldCout == true && m_isServer == true && Settings::GetInstance()->Get<bool>("output") == true)
	{
		std::cout << rhs.Get(true) << std::endl;
	}
}