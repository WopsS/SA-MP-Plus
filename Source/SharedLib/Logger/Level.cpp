#include <SharedLib.hpp>
#include <Logger/Level.hpp>

const std::string Log::LevelToString(const Level Level)
{
	switch (Level)
	{
		case Log::Level::Verbose:
		{
			return "VERBOSE";
		}
		case Log::Level::Debug:
		{
			return "DEBUG";
		}
		case Log::Level::Info:
		{
			return "INFO";
		}
		case Log::Level::Warning:
		{
			return "WARNING";
		}
		case Log::Level::Error:
		{
			return "ERROR";
		}
	}

	return fmt::format("UNKNOWN({})", static_cast<uint8_t>(Level));
}
