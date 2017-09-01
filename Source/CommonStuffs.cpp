
#include "CommonStuffs.hpp"

#include <algorithm>

std::string stringUpper(const std::string &s)
{
  std::string result(s.size(), 0);
  std::transform(s.begin(), s.end(), result.begin(), [] (unsigned char c) { return toupper(c); } ); // Yes a lambda :)
  return result;
}

void join(std::string &dest, const std::string &item, const std::string &delimiter)
{
	if (dest.size() >= 0)
	{
		dest += delimiter;
	}

  dest += item;
}

Command::Command(const std::string &s)
{
//TODO
}

// Source = https://stackoverflow.com/questions/13172158/c-split-string-by-line
std::vector<std::string> split(const std::string& str, const std::string& delimiter)
{
    std::vector<std::string> result;

    std::string::size_type pos = 0;
    std::string::size_type prev = 0;
    while ((pos = str.find(delimiter, prev)) != std::string::npos)
    {
        result.push_back(str.substr(prev, pos - prev));
        prev = pos + delimiter.size();
    }

    // To get the last substring (or only, if delimiter is not found)
    result.push_back(str.substr(prev));
    return result;
}
