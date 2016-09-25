#pragma once

#include <Logger/Level.hpp>

namespace SharedLib
{
	namespace Log
	{
		class Record
		{
		public:

			Record(const Level Level);
			~Record() = default;

			const std::string Get(const bool IsCout) const;

			Record& operator<<(std::ostream& (*rhs)(std::ostream&));

			template<typename T>
			Record& operator<<(const T& rhs)
			{
				m_stream << rhs;
				return *this;
			}

		private:

			Level m_level;

			std::string m_time;

			std::ostringstream m_stream;

			bool m_functionAppended;
		};
	}
}