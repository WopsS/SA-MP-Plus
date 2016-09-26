#pragma once

namespace Log
{
	enum class Level : uint8_t
	{
		Verbose = 0,
		Debug,
		Info,
		Warning,
		Error
	};

	const std::string LevelToString(const Level Level);
}