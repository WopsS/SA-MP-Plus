#include <SharedLib.hpp>
#include <Logger/Level.hpp>

const std::string SharedLib::Log::LevelToString(const Level Level)
{
	switch (Level)
	{
		case SharedLib::Log::Level::Verbose:
		{
			return "VERBOSE";
		}
		case SharedLib::Log::Level::Debug:
		{
			return "DEBUG";
		}
		case SharedLib::Log::Level::Info:
		{
			return "INFO";
		}
		case SharedLib::Log::Level::Warning:
		{
			return "WARNING";
		}
		case SharedLib::Log::Level::Error:
		{
			return "ERROR";
		}
	}

	return fmt::format("UNKNOWN({})", static_cast<uint8_t>(Level));
}
