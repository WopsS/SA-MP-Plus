#pragma once

namespace String
{
	const std::string Join(const std::vector<std::string>& Array, const char* Delimiter);

	const std::vector<std::string> Split(const std::string& Text, const char& Delimiter);
}