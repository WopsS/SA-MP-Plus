#include <SharedLib.hpp>
#include <Singleton/Singleton.hpp>

Settings::Settings()
{
	Add("logtimeformat", "[%H:%M:%S]");
}

void Settings::Add(const std::string& Key, const std::string& Value)
{
	// If the setting's key doesn't exists add it with the value, otherwise replace the value.
	if (m_settings.find(Key) == m_settings.end())
	{
		m_settings.emplace(Key, Value);
	}
	else
	{
		m_settings.at(Key) = Value;
	}
}

const bool Settings::Exists(const std::string& Key) const
{
	return m_settings.find(Key) != m_settings.end();
}

void Settings::Process(const std::string& Text, const char& Delimiter, const std::vector<std::string>& Excludes)
{
	// Ignore the line if we don't have the specified separator in it.
	if (Text.find(Delimiter) != std::string::npos)
	{
		// Check if we have something to exclude.
		for (auto& i : Excludes)
		{
			if (Text.substr(0, i.length()) == i)
			{
				return;
			}
		}

		auto Result = String::Split(Text, Delimiter);

		// If we have more than one delimiter characters on the line we will combine all values because it may be "hostname SA-MP 0.3 Server", etc.. 
		for (size_t i = 2; i < Result.size(); i++)
		{
			Result[1] += " " + Result[i];
		}

		// Add the option and the value(s) to the list.
		Add(Result[0], Result.size() >= 2 ? Result[1] : "");
	}
}

void Settings::Read(const std::string& Path, const char& Delimiter, const std::vector<std::string>& Excludes)
{
	std::fstream File(Path.c_str(), std::ios::in);
	std::string Line;

	// Read every line from the file and process it.
	while (std::getline(File, Line))
	{
		Process(Line, Delimiter, Excludes);
	}
}
