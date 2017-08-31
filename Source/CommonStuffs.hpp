
#ifndef COMMON_STUFFS
#define COMMON_STUFFS

#include <string>
#include <vector>

void join(std::string &dest, const std::string &item, const std::string& delimiter); // Little string accumulator helper
std::vector<std::string> split(const std::string& str, const std::string& delimiter); // Almost the opposite :)

class IAmDumpable
{
public:
  virtual std::string dump() = 0;
  //static void join(std::string &dest, const std::string &item);
};

//TODO: Fine tune this and implement it in the case stuff
class IAMPersistent
{
public:
  virtual void load() = 0;
  virtual void save() = 0;
};

//T0D0: Move this ? Or rename it event ? ...
class Command
{
public:
	Command(const std::string &s);
};

#endif // COMMON_STUFFS
