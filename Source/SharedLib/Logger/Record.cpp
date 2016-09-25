#include <SharedLib.hpp>
#include <Logger/Record.hpp>

SharedLib::Log::Record::Record(const Level Level)
	: m_level(Level)
{
	auto Time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	m_time = fmt::format(Settings::GetInstance()->Get<std::string>("logtimeformat"), *std::localtime(&Time));
}

const std::string SharedLib::Log::Record::Get(const bool IsCout) const
{
	std::ostringstream Result;

	if (IsCout == true)
	{
		Result << "[SA-MP+]";
	}
	else
	{
		Result << fmt::format("[{}] [{}] ", m_time, Log::LevelToString(m_level));
	}

	Result << m_stream.str();

	return Result.str();
}

SharedLib::Log::Record& SharedLib::Log::Record::operator<<(std::ostream& (*rhs)(std::ostream&))
{
	m_stream << rhs;
	return *this;
}
