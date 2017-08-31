
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <ctype.h>

#ifdef WIN32
#include <ciso646>
#endif

#include "KeywordCommands.hpp"
#include "AudioModules.hpp"
#include "UIElements.hpp"

using namespace std;

// Anonymous namespace to avoid eventual linking issue (C++ way).
// The old way consists of adding static keyword in front of the function signature
namespace
{

//TODO: Or move it to common stuff ?
// Does not seem to belong to the standard...
std::string string_upper(const std::string &s)
{
  string result(s.size(), 0);
  transform(s.begin(), s.end(), result.begin(), [] (unsigned char c) { return toupper(c); } ); // Yes a lambda :)
  return result;
}

}

bool KeywordCommand::process(std::string &what)
{
  // Heavy solution just for tokenization and upper case...
  std::stringstream ss(string_upper(what));
  std::vector<std::string> tokens{std::istream_iterator<std::string>{ss}, std::istream_iterator<std::string>{}};

  if ((tokens[0] == "QUIT") or (tokens[0] == "EXIT"))
  {
    what = "";
    return true; // Or false... Anyway we must break the main loop !
  }
  else if ((tokens[0] == "LS") or (tokens[0] == "DIR"))
  {
		MainScreen::getInstance()->writeLine(CaseSingleton::getInstance()->dump());
    return true;
  }
  else if ((tokens[0] == "CLS") or (tokens[0] == "CLEAR"))
  {
		MainScreen::getInstance()->clear2();
    return true;
  }
  else if ((tokens[0] == "?") or (tokens[0] == "HELP"))
  {
		MainScreen::getInstance()->writeLine("The known commands are :\nQUIT/EXIT : Leave USynth\nLS/DIR : List the case content\nCLS/CLEAR : Clear the screen and the command history");
		return true;
  }
  else
  {
    return false; // Unknown command !
  }
}
