
#ifndef COMMON_STUFFS
#define COMMON_STUFFS

#include <string>
#include <vector>

//std::experimental::filesystem::path::preferred_separator which should return either / or \ depending on your platform.
#ifdef WIN32
#define PATH_SEPARATOR '\\'
#else
#define PATH_SEPARATOR '/'
#endif

#ifdef WIN32
#include <ciso646> // and and or keyword support :)
#endif

// Source = http://www.cplusplus.com/forum/general/33669/
template <typename T, unsigned size>
inline unsigned sizeOfArray(const T(&)[size]) { return size; }

enum class Target { screen, midi, command, device, misc, last_item }; //TODO: Refine midi by channel ?
const std::string targets[(int) Target::last_item] = { "screen", "midi", "command", "device", "misc" }; // Don't forget the leading const :)

std::string intToStr(int value); // So Delpĥi...
std::string runningFolder();
std::string stringUpper(const std::string& s);
void join(std::string& dest, const std::string& item, const std::string& delimiter); // Little string accumulator helper
std::vector<std::string> split(const std::string& str, const std::string& delimiter); // Almost the opposite :)
void logThis(const char* s, Target t); //TODO: Go to this (std::string &s, target t) ? Or better, use stream ?
std::string appendPath(const std::vector<std::string>& pieces);
void createLogFolders(); // Turn the logger in to a singleton ?

class IAmDumpable
{
public:
  virtual std::string dump() = 0;
  //static void join(std::string &dest, const std::string &item);
};

//TODO: Fine tune this and implement it in the case stuff
class IAmPersistent
{
public:
  virtual void load() = 0;
  virtual void save() = 0;
};

enum class Folder { cases, configurations, logs, modules, projects, scripts, last_item }; //TODO: Add samples ?
const std::string folders[(int) Folder::last_item] = { "cases", "configurations", "logs", "modules", "projects", "scripts" };


//T0D0: Move this ? Or rename it event ? ...
class Command
{
public:
	Command(const std::string &s);
};

#endif // COMMON_STUFFS
