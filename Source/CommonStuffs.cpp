
#include "CommonStuffs.hpp"
#include "ConfigurationFiles.hpp"

#include <algorithm>
#include <iostream>
#include <ctime>
#include <sstream>

// C++17 only : defined in the upcoming C++ 17 standard
// #include <filesystem>
//std::string path = std::filesystem::current_path();

// See https://stackoverflow.com/questions/143174/how-do-i-get-the-directory-that-a-program-is-running-from
// In the meantime :
//#include <experimental/filesystem>
//std::string path = std::experimental::filesystem::current_path();

#ifdef WIN32 // Don't use WINDOWS !
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

// Can't understand why there is no shorter way to perform this conversion...
std::string intToStr(int value)
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}

// No real standard c++ to do this... See above !
std::string runningFolder()
{
	char cCurrentPath[FILENAME_MAX];

	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath)))
	{
		return ".";
	}

	cCurrentPath[sizeof(cCurrentPath) - 1] = '\0'; /* not really required */
	return std::string(cCurrentPath);
}

std::string stringUpper(const std::string &s)
{
  std::string result(s.size(), 0);
  std::transform(s.begin(), s.end(), result.begin(), [] (unsigned char c) { return toupper(c); } ); // Yes a lambda :)
  return result;
}

std::string appendPath(const std::vector<std::string> &pieces)
{
	std::string result;

	for (std::string piece : pieces)
	{
		result += piece; // auto usage was ok here but not in the line below :(
		if (piece.back() != PATH_SEPARATOR)
		{
			result += PATH_SEPARATOR;
		}
	}

	//std::cout << "result = " << result << std::endl;
	result.erase(result.end()-1); // Remove the trailing path separator :-)
	//std::cout << "result2 = " << result << std::endl;
	return result;
}

void join(std::string &dest, const std::string &item, const std::string &delimiter)
{
	if (dest.size() > 0)
	{
		dest += delimiter;
	}

  dest += item;
}

Command::Command(const std::string &s)
{
//TODO: ?
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

/*
// C++17 or Boost...
#include <experimental/filesystem> // or #include <filesystem>
namespace fs = std::experimental::filesystem;
void createLogFolders()
{
	for (auto s : folders)
	{
		if (!fs::exists(s))
		{
			fs::create_directory(s);
		}
	}
}
*/

void logThis(const char *s, Target t)
{
  if (GlobalConfigurationSingleton::instance()->keyValue("log", targets[(int) t]) == "0")
  {
		return;
  }

	time_t rawtime;
  struct tm* timeinfo;
  char timestamp[32]; // Sure there is more C++ way to do this...

  time (&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(timestamp, sizeof(timestamp), "%d/%m/%Y %H:%M:%S", timeinfo);

  std::string fullFilename = appendPath({ runningFolder(), folders[(int) Folder::logs], targets[(int) t] }) + ".log";
  //std::cout << "fullFilename = " << fullFilename << std::endl;
  FILE *fLog = fopen(fullFilename.c_str(), "a");
  fprintf(fLog, "%s => %s\n", timestamp, s);
  fclose(fLog);
}

// Enable the logger
//#define LOG_THIS(what) logThis(what)
// Disable the logger
//#define LOG_THIS(what)
