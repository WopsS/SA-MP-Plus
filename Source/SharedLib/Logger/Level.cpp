#include <SharedLib.hpp>
#include <Logger/Level.hpp>

const std::string SharedLib::Log::LevelToString(const Level Level)
{
	switch (Level)
	{
		case Level::Verbose:
		{
			return "VERBOSE";
		}
		case Level::Debug:
		{
			return "DEBUG";
		}
		case Level::Info:
		{
			return "INFO";
		}
		case Level::Warning:
		{
			return "WARNING";
		}
		case Level::Error:
		{
			return "ERROR";
		}
	}

	return fmt::format("UNKNOWN({})", static_cast<uint8_t>(Level));
}
