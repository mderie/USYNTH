
#ifndef COMMON_STUFFS
#define COMMON_STUFFS

#include <string>

void join(std::string &dest, const std::string &item); // Little string accumulator helper

class IAmDumpable
{
public:
  virtual std::string dump() = 0;
  //static void join(std::string &dest, const std::string &item);
};

// Or event ?
class Command
{
public:
	Command(const std::string &s);
};

#endif // COMMON_STUFFS
