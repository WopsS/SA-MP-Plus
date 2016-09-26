#pragma once

namespace SharedLib
{
	class Settings : public Singleton<Settings>
	{
	public:

		void Add(const std::string& Key, const std::string& Value);

		const bool Exists(const std::string& Key) const;

		template<typename T>
		T Get(const std::string& Key) const
		{		
			if (m_settings.find(Key) == m_settings.end())
			{
				return T();
			}

			T Result;
			std::istringstream Stream(m_settings.at(Key));

			Stream >> Result;

			return Result;
		}

		template<typename T>
		const T GetLength(const std::string& Key) const
		{
			if (m_settings.find(Key) == m_settings.end())
			{
				return T();
			}

			return m_settings.at(Key).length();
		}

		void Process(const std::string& Text, const char& Delimiter, const std::vector<std::string>& Excludes = {});

		void Read(const std::string& Path, const char& Delimiter, const std::vector<std::string>& Excludes = {});

	private:

		friend class Singleton<Settings>;

		Settings();
		~Settings() = default;

		std::unordered_map<std::string, std::string> m_settings;
	};
}