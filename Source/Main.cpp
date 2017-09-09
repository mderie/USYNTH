
/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include <iostream>
#include <string>

#include "../JuceLibraryCode/JuceHeader.h"

/*
#ifdef WIN32
#include <curses.h> //TODO: Check name ! ==> Done, same name :)
// Source : https://stackoverflow.com/questions/31821159/compile-simple-c-code-in-visual-studio-2013
#include <windows.h>
#define sleep(s) Sleep((s) * 1000) // For Sleep (notice the weird capital...)
#else
#include <curses.h>
#include <unistd.h> // For sleep()
#endif
*/

// Sources of inspiration
//
// https://learningmodular.com/
// https://www.modulargrid.net/
// http://www.soundonsound.com/reviews/secret-world-modular-synthesizers
// ...

//TODO: Fine tune this list of prj include...
#include "LaunchpadPrimitives.hpp" // To be replaced by BCR20000 !
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
//using namespace std;

//==============================================================================
int main (int argc, char* argv[])
{
	//TODO: Log "Starting a new session"

    // std::cout << "Welcome to USynth (reloaded) - the Sound EXplorer - Coded by Sam TFL/TDV" << std::endl;

    // Create here all the global objects (argh !-)
    //MainScreen ms;

    //if (GlobalConfigurationSingleton::getInstance()->getKeyValue("ShowAboutAtStartup") == "1")
    //{
    //TODO: Review this !
		//	MainScreenSingleton::getInstance()->writeLine("TODO...");
    //}

    //ConfigurationFile ?;

    /*
    auto keys = cf.getKeys(); // I'm so lazy :)
    if (std::find(keys.begin(), keys.end(), "ROTC11") != keys.end())
    {
			std::cout << "Found key = ROTC11 with value" << cf.getKeyValue("ROTC11") << std::endl;
    }
    */

    //TODO: Log "Starting the main loop"

		std::string s;
		char command[255] = ""; // I'm too lazy to convert ncurses char * based code...
    while (true)
    {
      MainScreenSingleton::getInstance()->rebuild();
      MainScreenSingleton::getInstance()->readLine(command, sizeof(command));
      s = std::string(command); // Back to C++ world...

		  if (s.size() == 0)
		  {
				continue; // Easy case : empty command... Skip it !
		  }

			if (!KeywordCommand::process(s))
			{
			  MainScreenSingleton::getInstance()->writeLine("Unrecognized command : " + s);
				continue;
			}
			else if (s.size() == 0)
      {
				// Special case were process() clear provided the command
				if (YesNoDialog::execute("Do you really want to leave (y/n) ?"))
				{
					//TODO: Check first for unsaved stuff !!!
					break; // Command known but still we have to leave :)
				}
      }
    } // while(true)

    // Unload stuff here... Destroy the singletons :)
	MainScreenSingleton::getInstance()->~MainScreenSingleton();

	//TODO: Log "Stopping  a new session"

	return 0;
}
