
#include <iostream>

#include "UIElements.hpp"

void MainScreen::show()
{
    /*  Initialize ncurses  */
    if ((m_mainwin = initscr()) == NULL)
    {
        std::cout << "curses oups in MainScreen::show" << std::endl;
        return;
    }

    mvaddstr(13, 33, "USynth>");
    refresh();
}

MainScreen::~MainScreen()
{
    /*  Clean up after ourselves  */
    delwin(m_mainwin);
    endwin();
    refresh();
}

// Old school he ?-)
void MainScreen::drawBorders()
{
  int x, y, i;

  getmaxyx(screen, y, x);

  // 4 corners
  mvwprintw(screen, 0, 0, "+");
  mvwprintw(screen, y - 1, 0, "+");
  mvwprintw(screen, 0, x - 1, "+");
  mvwprintw(screen, y - 1, x - 1, "+");

  // sides
  for (i = 1; i < (y - 1); i++) {
    mvwprintw(screen, i, 0, "|");
    mvwprintw(screen, i, x - 1, "|");
  }

  // top and bottom
  for (i = 1; i < (x - 1); i++) {
    mvwprintw(screen, 0, i, "-");
    mvwprintw(screen, y - 1, i, "-");
  }
}

std::string MainScreen::nextCommand()
{
	lastlines.emplace_back(""); // use then mvaddstr ?
	//show();

	return "";
}

void commandOuput(std::string &s)
{
	//TODO
}
