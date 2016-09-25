#include <SharedLib.hpp>
#include <Utils/String.hpp>

const std::string SharedLib::String::Join(const std::vector<std::string>& Array, const char* Delimiter)
{
	std::ostringstream Result;
	std::copy(Array.begin(), Array.end(), std::ostream_iterator<std::string>(Result, Delimiter));

	return Result.str();
}

const std::vector<std::string> SharedLib::String::Split(const std::string& Text, const char& Delimiter)
{
	std::vector<std::string> Result;
	std::stringstream Stream(Text);
	std::string String;

	while (std::getline(Stream, String, Delimiter))
	{
		Result.push_back(String);
	}

	return Result;
}
