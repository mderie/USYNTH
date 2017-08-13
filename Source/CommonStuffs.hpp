
#ifndef COMMON_STUFFS
#define COMMON_STUFFS

#include <string>

class IAmDumpable
{
public:
  virtual std::string dump() = 0;
  static void join(std::string &dest, const std::string &item);
};

#endif // COMMON_STUFFS
