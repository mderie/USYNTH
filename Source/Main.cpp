
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

int main (int argc, char* argv[])
{
	std::cout << "Please check that all the required folders exist !" << std::endl;
	//createLogFolders();
	//check for all the other folder existenz !
	std::cout << "ahu ?" << std::endl;
	logThis("Starting a new session", Target::misc);
	std::cout << "ahu !" << std::endl;
	/*
	testDebile = juce::MidiInput::op Devices();
	for (auto item : testDebile)
	{
		std::cout << "main :" << std::endl;
		logThis(item.toUTF8(), Target::device);
	}
	*/

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

    juce::StringArray iDevices = listAllInputDevices();
    //std::cout << "Never reached :(" << std::endl;
    juce::StringArray oDevices = listAllOutputDevices();
    //std::cout << "Device list done !" << std::endl;
    CaseSingleton::instance()->add(new OutModule());
    logThis("Starting the main loop", Target::misc);

		std::string s;
		char command[255] = ""; // I'm too lazy to convert ncurses char * based code...
    while (true)
    {
      MainScreenSingleton::instance()->rebuild();
      MainScreenSingleton::instance()->readLine(command, sizeof(command));
      s = std::string(command); // Back to C++ world...

		  if (s.size() == 0)
		  {
				continue; // Easy case : empty command... Skip it !
		  }

			if (!KeywordCommand::process(s))
			{
			  MainScreenSingleton::instance()->writeLine("Unrecognized command : " + s);
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

	std::cout << "About to delete MainScreenSingleton" << std::endl;
	// Unload stuff here... Destroy the singletons :)
	//MainScreenSingleton::instance()->~MainScreenSingleton();
	delete MainScreenSingleton::instance();

	// Useless to call manually the dtor, it is delete's job !
	// https://stackoverflow.com/questions/677653/does-delete-call-the-destructor
	//CaseSingleton::instance()->~CaseSingleton();
	std::cout << "About to delete CaseSingleton" << std::endl;
	delete CaseSingleton::instance(); // Fake warning  !-) https://github.com/Benjamin-Dobell/Heimdall/issues/69

	std::cout << "About to delete GlobalConfigurationSingleton" << std::endl;
	delete ((ConfigurationFile*) GlobalConfigurationSingleton::instance()); //TODO: Care instance() here is in fact a ConfigurationFile !!!
	// Calling delete is safe on nullptr :
	// https://stackoverflow.com/questions/6731331/is-it-still-safe-to-delete-nullptr-in-c0x

	logThis("Stopping the current session", Target::misc);

	// delete logger singleton here if any !

	std::cout << "That's all folks" << std::endl;
	return 0;
}
