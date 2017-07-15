/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#include <iostream>

#include "../JuceLibraryCode/JuceHeader.h"

#ifdef WIN32
#include <pdcurses.h> //TODO: Check name !
#else
#include <curses.h>
#endif

#include <unistd.h> // for sleep()

using namespace std;

//==============================================================================
int main (int argc, char* argv[])
{
    WINDOW * mainwin;

    /*  Initialize ncurses  */
    if ( (mainwin = initscr()) == NULL ) {
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

    cout << "Welcome to USynth Reloaded / The sound explorer" << endl;
    return 0;
}