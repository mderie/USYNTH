
/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include <iostream>

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
//TODO: create #include "Console.hpp" ?
//TODO: create #include "Timer.hpp" ?
//TODO: create #include "AudioOuts.hpp" ?

using namespace std;

//==============================================================================
int main (int argc, char* argv[])
{
    // <ncurses sample code>
    WINDOW * mainwin;

    /*  Initialize ncurses  */
    if ((mainwin = initscr()) == NULL)
    {
        fprintf(stderr, "Error initialising ncurses.\n");
        exit(EXIT_FAILURE);
    }

    /*  Display "Hello, world!" in the centre of the
	screen, call refresh() to show our changes, and
	sleep() for a few seconds to get the full screen effect  */
    mvaddstr(13, 33, "Hello, world!");
    refresh();
    sleep(3);

    /*  Clean up after ourselves  */
    delwin(mainwin);
    endwin();
    refresh();
    // </ncurses sample code>

    cout << "Welcome to USynth (reloaded) - the Sound EXplorer - Coded by Sam TFL/TDV" << endl;
    return 0;
}
