#include <SharedLib.hpp>
#include <Logger/Record.hpp>

Log::Record::Record(const Level Level)
	: m_level(Level)
{
	std::time_t Time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::ostringstream Stream;

	Stream << std::put_time(std::localtime(&Time), Settings::GetInstance()->Get<std::string>("logtimeformat").c_str());
	m_time = Stream.str();
}

const std::string Log::Record::Get(const bool IsCout) const
{
	std::ostringstream Result;

	if (IsCout == true)
	{
		Result << "[SA-MP+]";
	}
	else
	{
		Result << m_time << " " << "[" << Log::LevelToString(m_level) << "] ";
	}

	Result << m_stream.str();

	return Result.str();
}

Log::Record& Log::Record::operator<<(std::ostream& (*rhs)(std::ostream&))
{
	m_stream << rhs;
	return *this;
}
