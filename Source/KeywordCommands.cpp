
#include "KeywordCommands.hpp"

#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

// Does not seem to belong to the standart...
string string_upper(const string &s)
{
  string result(s.size(), 0);
  transform(s.begin(), s.end(), result.begin(), [] (unsigned char c) { return std::toupper(c); } );
  return result;
}

bool KeywordCommand::process(const std::string &what)
{
  // Heavy solution just for tokenization and upper case...
  stringstream ss(string_upper(what));
  vector<string> tokens{istream_iterator<string>{ss}, istream_iterator<string>{}};

  if ((tokens[0] == "QUIT") or (tokens[0] == "EXIT"))
  {

    return true;
  }
  else if ((tokens[0] == "LS") or (tokens[0] == "DIR"))
  {

    return true;
  }
  else
  {
    return false;
  }
}
