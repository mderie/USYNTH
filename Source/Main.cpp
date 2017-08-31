
/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include <iostream>
#include <string>

// Defined in the upcoming C++ 17 standard
// #include <filesystem>

#include "../JuceLibraryCode/JuceHeader.h"

#ifdef WIN32
#include <curses.h> //TODO: Check name ! ==> Done, same name :)
// Source : https://stackoverflow.com/questions/31821159/compile-simple-c-code-in-visual-studio-2013
#include <windows.h>
#define sleep(s) Sleep((s) * 1000) // For Sleep (notice the weird capital...)
#else
#include <curses.h>
#include <unistd.h> // For sleep()
#endif

#ifdef WIN32 // Don't use WINDOWS !
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

// No real standard c++ to do this...
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

// Sources of inspiration
//
// https://learningmodular.com/
// https://www.modulargrid.net/
// http://www.soundonsound.com/reviews/secret-world-modular-synthesizers
// ...

//TODO: Fine tune this list of prj include...
#include "LaunchpadPrimitives.hpp"
#include "AudioBuffers.hpp"
#include "AudioModules.hpp"
#include "KeywordCommands.hpp"
#include "MidiCommands.hpp"
#include "MidiNotes.hpp"
#include "ConfigurationFiles.hpp"
#include "UIElements.hpp"
#include "CommonStuffs.hpp"
#include "ThreadedTimers.hpp"
#include "AudioDevices.hpp"

// To be removed ?
using namespace std;

//==============================================================================
int main (int argc, char* argv[])
{
	char command[255] = ""; // I'm too lazy to convert ncurses char * based code...

    // std::cout << "Welcome to USynth (reloaded) - the Sound EXplorer - Coded by Sam TFL/TDV" << std::endl;

    // C++17 only
    //std::string path = std::filesystem::current_path();
    //std::cout << "path = " << runningFolder() << std::endl;

    // Create here all the global objects (argh !-)
    //MainScreen ms;

    std::string s;
    ConfigurationFile cf(runningFolder() + string("/mapping.ini"));

    //ConfigurationFile ?;

    /*
    auto keys = cf.getKeys(); // I'm so lzay :)
    if (std::find(keys.begin(), keys.end(), "ROTC11") != keys.end())
    {
			std::cout << "Found key = ROTC11 with value" << cf.getKeyValue("ROTC11") << std::endl;
    }
    */

    //Message msg;
    while (true)
    {
      MainScreen::getInstance()->rebuild();
      MainScreen::getInstance()->readLine(command, sizeof(command));
      s = string(command); // Back to C++ world...

		  if (s.size() == 0)
		  {
				continue; // Easy case : empty command...
		  }

			if (!KeywordCommand::process(s))
			{
			  MainScreen::getInstance()->writeLine("Unrecognized command : " + s);
				continue;
			}
			else if (s.size() == 0)
      {
        //TODO: Check first for unsaved stuff !!!
				break; // Command known but still we have to leave :)
      }
    }

    // Unload stuff here... Destroy the singletons :)
    MainScreen::getInstance()->~MainScreen();

    return 0;
}
