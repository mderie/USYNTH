
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
/*
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

} // namespace !-)
*/

bool KeywordCommand::process(std::string &what)
{
  // Heavy solution just for tokenization and upper case...
  std::stringstream ss(stringUpper(what));
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
  // Global alternative sample : else if (stringUpper(tokens[0]) == "ADD")
  else if (tokens[0] == "ADD")
  {
    if (tokens.size() != 2)
    {
      MainScreen::getInstance()->writeLine("The ADD command expects one parameter, ie : VCO, LFO, ...");
			return true; // Although we did not do anything...
    }
    Kind kind = moduleKind(tokens[1]);
    if (kind == Kind::LAST_ITEM)
    {
      MainScreen::getInstance()->writeLine("Unknown module : " + tokens[1]);
			return true; // Id.
    }

    AudioModule* module = CreateModuleFactory(kind);
    if (module == nullptr)
    {
      MainScreen::getInstance()->writeLine("Module : " + tokens[1] + " not yet implemented, sorry!");
			return true;
    }

		CaseSingleton::getInstance()->add(module);
    return true;
  }
  else if ((tokens[0] == "REMOVE") or (tokens[0] == "DELETE"))
  {
		//TODO
    return true;
  }
  else if (tokens[0] == "PLAY")
  {
		//TODO
    return true;
  }
  else if (tokens[0] == "STOP")
  {
		//TODO
    return true;
  }
  else if (tokens[0] == "LOAD")
  {
		//TODO
    return true;
  }
  else if (tokens[0] == "SAVE")
  {
		//TODO
    return true;
  }
  else if (tokens[0] == "ABOUT")
  {
		MainScreen::getInstance()->writeLine("Welcome to USynth (reloaded) - the Sound EXplorer - Coded by Sam TFL/TDV - Project started somewhere in 2017");
		MainScreen::getInstance()->writeLine("                    The sole console based modular synth ? ==> So the most powerfull !-)");
		return true;
  }

  else if ((tokens[0] == "?") or (tokens[0] == "HELP"))
  {
		MainScreen::getInstance()->writeLine("Here's the known commands so far :\n\nQUIT / EXIT : Leave USynth\nLS / DIR : List the case content\nCLS / CLEAR : Clear the screen and the command history");
		return true;
  }
  else
  {
    return false; // Unknown command !
  }
}
