
#include <sstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <ctype.h>

#include "KeywordCommands.hpp"
#include "AudioModules.hpp"
#include "UIElements.hpp"
#include "CommonStuffs.hpp"

using namespace std;

// Anonymous namespace to avoid eventual linking issue (C++ way).
// The old way consists of adding static keyword in front of the function signature !
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

  if (((tokens[0] == "QUIT") or (tokens[0] == "EXIT")) and (tokens.size() == 1))
  {
    what = "";
    return true; // Or false... Anyway we must break the main loop !
  }
  else if (((tokens[0] == "LS") or (tokens[0] == "DIR")) and (tokens.size() == 1))
  {
		MainScreenSingleton::instance()->writeLine(CaseSingleton::instance()->dump());
    return true;
  }
  else if (((tokens[0] == "CLS") or (tokens[0] == "CLEAR")) and (tokens.size() == 1))
  {
		MainScreenSingleton::instance()->clear2();
    return true;
  }
  // Global alternative sample : else if (stringUpper(tokens[0]) == "ADD")
  else if ((tokens[0] == "ADD") or (tokens[0] == "INSERT"))
  {
    if ((tokens.size() > 2) or (tokens.size() == 1))
    {
      MainScreenSingleton::instance()->writeLine("The ADD / INSERT command expects one parameter only, ie : VCO, LFO, ...");
			return true; // Although we did not do anything...
    }

    if ((tokens[1] == "?") or (tokens[1] == "HELP"))
    {
      MainScreenSingleton::instance()->writeLine("The ADD / INSERT command expects one of the following parameter :");
      std::string sb;
      for (auto& s : Kinds)
      {
				join(sb, s, ",");
      }
      MainScreenSingleton::instance()->writeLine(sb);
			return true;
    }

    Kind kind = moduleKind(tokens[1]);
    if (kind == Kind::LAST_ITEM)
    {
      MainScreenSingleton::instance()->writeLine("Unknown module : " + tokens[1]);
			return true; // Id.
    }

    if (kind == Kind::SPK)
    {
			MainScreenSingleton::instance()->writeLine("SPK module is unique and already exists !");
			return true;
    }

    AudioModule* module = CreateModuleFactory(kind);
    if (module == nullptr)
    {
      MainScreenSingleton::instance()->writeLine("Module : " + tokens[1] + " not yet implemented, sorry!");
			return true;
    }

		CaseSingleton::instance()->add(module);
    return true;
  }
  else if ((tokens[0] == "REMOVE") or (tokens[0] == "DELETE"))
  {
		/*
		Kind kind = moduleKind(tokens[1]);
    if (kind == Kind::SPK)
    {
			MainScreenSingleton::instance()->writeLine("SPK module can't be removed !");
			return true;
    }
    */

    return true;
  }
  else if ((tokens[0] == "PACTH") or (tokens[0] == "LINK"))
  {
		//TODO: Make the bridge !-)
    return true;
  }
  else if ((tokens[0] == "LOAD") or (tokens[0] == "READ"))
  {
		//TODO: Load project / configuration
    return true;
  }
  else if ((tokens[0] == "SAVE") or (tokens[0] == "WRITE"))
  {
		//TODO: Save project / configuration
    return true;
  }
  else if ((tokens[0] == "SET") or (tokens[0] == "PUSH"))
  {
		//TODO
    return true;
  }
  else if ((tokens[0] == "GET") or (tokens[0] == "PULL"))
  {
		//TODO
    return true;
  }
  else if (((tokens[0] == "PLAY") or (tokens[0] == "START")) and (tokens.size() == 1))
  {
		// Not sure if a cable must be case element
		//if (CaseSingleton::instance()->element("SPK").?)
		//{
		//	MainScreenSingleton::instance()->writeLine("Oups ! Nothing goes to the SPK module !");
		//}
		//else
		{
			//TODO: Start the audio device
			MainScreenSingleton::instance()->writeLine("No sound at all ? Verify that something goes into the SPK module IN !");
		}
    return true;
  }
  else if (((tokens[0] == "PAUSE") or (tokens[0] == "STOP")) and (tokens.size() == 1))
  {
		//TODO: Stop the audio device
    return true;
  }
  else if ((tokens[0] == "ABOUT") and (tokens.size() == 1))
  {
		//TODO: Check what we can do if the text is widder thant the screen
		MainScreenSingleton::instance()->writeLine("Welcome to USynth (reloaded) - the Sound EXplorer - Coded by Sam TFL/TDV - Project started somewhere in 2017");
		MainScreenSingleton::instance()->writeLine("                    The sole console based modular synth ? ==> So the most powerfull !-)");
		return true;
  }

  else if (((tokens[0] == "?") or (tokens[0] == "HELP")) and (tokens.size() == 1))
  {
		MainScreenSingleton::instance()->writeLine("Here's the known commands so far :\n");
		MainScreenSingleton::instance()->writeLine("QUIT / EXIT : Leave USynth");
		MainScreenSingleton::instance()->writeLine("LS / DIR : Describe the case content");
		MainScreenSingleton::instance()->writeLine("CLS / CLEAR : Erase the screen and the command history");
		MainScreenSingleton::instance()->writeLine("ADD / INSERT module_name : populate the current case with the given module");
		MainScreenSingleton::instance()->writeLine("REMOVE / DELETE module_name : suppress the given module from the current case");
		MainScreenSingleton::instance()->writeLine("PATCH / LINK module_name.out_name module_name.in_name");
		// Needed ?
		// MainScreenSingleton::instance()->writeLine("UNPATCH / UNLINK");
		MainScreenSingleton::instance()->writeLine("LOAD / READ : Get file conten");
		MainScreenSingleton::instance()->writeLine("SAVE / WRITE : Set file content");
		MainScreenSingleton::instance()->writeLine("SET / PUSH : module_name.pot value or module_name.swich value");
		MainScreenSingleton::instance()->writeLine("GET / PULL : module_name.pot or module_name.swich");
		MainScreenSingleton::instance()->writeLine("PLAY / START : Sound ignition !");
		MainScreenSingleton::instance()->writeLine("PAUSE / STOP : Silence now !");
		return true;
  }
  else
  {
    return false; // Unknown command !
  }
}
