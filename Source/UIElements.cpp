
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

// Faking a namespace to avoid name collisions... Doesn't work since curses is full of macros :(
//Neither preceding every cursed stuff by ::
// Maybe should I try this : https://stackoverflow.com/questions/29556093/give-namespace-to-an-existing-library-in-c
//namespace curses
//{
#include <curses.h>
//}

// Some C headers that goes with ncurses... And my primitive logger
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Instead of renaning my functions scroll2 & clear2, I could have put this include before the curses one and use this
#include "UIElements.hpp"
#include "CommonStuffs.hpp"

#define WASTED_SCREEN_LINES 4 // Top line + 3 lines at the bottom of the screen
#define OUTPUT_LINES_MAX 255

/*
FILE *fLog;
// Care : a "log" macro already exists...
void logThis(const char *what)
{
  fLog = fopen("log.txt", "a");
  fprintf(fLog, "%s\n", what);
  fclose(fLog);
}

// Enable the logger
//#define LOG_THIS(what) logThis(what)
// Disable the logger
#define LOG_THIS(what)
*/

MainScreenSingleton *MainScreenSingleton::s_instance = nullptr;
MainScreenSingleton *MainScreenSingleton::getInstance()
{
	if (s_instance == nullptr)
	{
		s_instance = new MainScreenSingleton();
	}
	return s_instance;
}

MainScreenSingleton::MainScreenSingleton()
{
  initscr(); // Initialize ncurses
  cbreak(); // No line buffering
  keypad(stdscr, TRUE); // Allow extended key like F1
  curs_set(TRUE); // We want to see the cursor
  noecho(); // We handle the characters output at cursor

  getmaxyx(stdscr, m_maxY, m_maxX);
}

MainScreenSingleton::~MainScreenSingleton()
{
	endwin();
}

void MainScreenSingleton::scroll2()
{
	logThis("MainScreenSingleton::scroll2 ==> Entering", target::screen);
  if (m_lines.size() == 0)
  {
		logThis("MainScreenSingleton::scroll2 ==> Leaving : Nothing to do !", target::screen);
    return;
  }

  for (size_t i = 1; i < m_lines.size(); i++)
  {
    m_lines[i - 1] = m_lines[i];
  }

  logThis("MainScreenSingleton::scroll2 ==> Boum next line ?", target::screen);
  m_lines.erase(m_lines.end());
  logThis("MainScreenSingleton::scroll2 ==> Leaving", target::screen);
}

void MainScreenSingleton::clear2()
{
	logThis("MainScreenSingleton::clear2 ==> Entering", target::screen);
  m_lines.clear();
  logThis("MainScreenSingleton::clear2 ==> Leaving", target::screen);
}

void MainScreenSingleton::show()
{
	logThis("MainScreenSingleton::show ==> Entering", target::screen);
	if (m_lines.size() == 0)
  {
		logThis("MainScreenSingleton::show ==> Leaving : Nothing to do !", target::screen);
    return;
  }

  int firstLineOffset = 0; // We start at the first line of the buffer
  // Except if we have more lines in the buffer than the screen
  if ((int) m_lines.size() > m_maxY - WASTED_SCREEN_LINES)
  {
    logThis("MainScreen::show ==> Correcting firstLineOffset value", target::screen);
    firstLineOffset = m_lines.size() - m_maxY + WASTED_SCREEN_LINES;
  }

  char snum[9];
  logThis("MainScreen::show ==> firstLineOffset = ...", target::screen);
  sprintf(snum, "%d", firstLineOffset);
  logThis(snum, target::screen);
  logThis("MainScreen::show ==> m_maxY - WASTED_SCREEN_LINES = ...", target::screen);
  sprintf(snum, "%d", m_maxY - WASTED_SCREEN_LINES);
  logThis(snum, target::screen);

  for(int i = 1; i < m_maxY - WASTED_SCREEN_LINES + 1; i++)
  {
     logThis("MainScreen::show ==> i + firstLineOffset - 1 = ...", target::screen);
     sprintf(snum, "%d", i + firstLineOffset - 1);
     logThis(snum, target::screen);
     logThis("MainScreen::show ==> m_lines[i + firstLineOffset - 1] = ...", target::screen);
     logThis(m_lines[i + firstLineOffset - 1].c_str(), target::screen);

     mvwprintw(stdscr, i, 1, m_lines[i + firstLineOffset - 1].c_str());

     if ((i + firstLineOffset - 1) == (((int) m_lines.size()) - 1))
     {
				logThis("MainScreen::show ==> Last line displayed", target::screen);
        break; // We are at the end of our buffer
     }
  }

  logThis("MainScreen::show ==> Leaving", target::screen);
}

void MainScreenSingleton::rebuild()
{
	logThis("MainScreenSingleton::rebuild ==> Entering", target::screen);
  getmaxyx(stdscr, m_maxY, m_maxX); // Get the screen height & width
  clear(); // We repaint all the screen each time !
	box(stdscr, ACS_VLINE, ACS_HLINE);
	wmove(stdscr, m_maxY - 3, 1);
	hline(ACS_HLINE, m_maxX - 2);
	show();
	mvwprintw(stdscr, m_maxY - 2, 1, "USynth> ");
	refresh();
	logThis("MainScreenSingleton::rebuild ==> Leaving", target::screen);
}

std::string MainScreenSingleton::readLine(char *buffer, int buflen)
{
  memset(buffer, 0x00, buflen);
  move(m_maxY - 2, 9);
  int old_curs = curs_set(1);
  int pos = 0;
  int len = 0;
  int x, y;

  getyx(stdscr, y, x); // Get the current position...
  for (;;)
  {
    int c;

    buffer[len] = ' ';
    mvaddnstr(y, x, buffer, len + 1); // Print the buffer content
    move(y, x + pos);

    c = getch();

    if (c == KEY_ENTER || c == '\n' || c == '\r')
    {
      break;
    }
    else if (isprint(c))
    {
      if (pos < buflen - 1)
      {
        memmove(buffer + pos + 1, buffer + pos, len - pos);
        buffer[pos++] = c;
        len += 1;
      }
      else
      {
        beep();
      }
    }
    else if (c == KEY_HOME)
    {
			if (pos > 0)
			{
				pos = 0;
			}
			else
			{
				beep();
			}
    }
    else if (c == KEY_END)
    {
			if (pos < len)
			{
				pos = len;
			}
			else
			{
				beep();
			}
    }
    else if (c == KEY_LEFT)
    {
      if (pos > 0)
      {
        pos -= 1;
      }
      else
      {
       beep();
      }
    }
    else if (c == KEY_RIGHT)
    {
      if (pos < len)
      {
       pos += 1;
       }
       else
       {
        beep();
       }
    }
    else if (c == KEY_BACKSPACE)
    {
      if (pos > 0)
      {
        memmove(buffer + pos - 1, buffer + pos, len - pos);
        pos -= 1;
        len -= 1;
      }
      else
      {
        beep();
      }
    }
    else if (c == KEY_DC)
    {
      if (pos < len)
      {
        memmove(buffer + pos, buffer + pos + 1, len - pos - 1);
        len -= 1;
      }
      else
      {
        beep();
      }
    }
    else
    {
      beep();
    }
  } // for (;;)

  buffer[len] = '\0';
  if (old_curs != ERR)
  {
   /*
   for (int i = 0; i < len; i++)
   {
      mvaddch(y, x + i, ' ');
   }
   */
   curs_set(old_curs);
	}

	return std::string(buffer);
}

void MainScreenSingleton::writeLine(const std::string &s)
{
	logThis("MainScreenSingleton::writeLine ==> Entering, s = ...", target::screen);
	logThis(s.c_str(), target::screen);
  char snum[9];
  sprintf(snum, "%d", (int) m_lines.size());
  logThis(snum, target::screen);

  std::vector<std::string> tokens = split(s, "\n");
  // Yet another lambda :) "&" means here "this", see :
  // https://stackoverflow.com/questions/4940259/lambdas-require-capturing-this-to-call-static-member-function
  auto push = [&](const std::string& token) { m_lines.push_back(token); logThis(token.c_str(), target::screen); };
  std::for_each(tokens.begin(), tokens.end(), push);

  //m_lines.push_back(s);

  sprintf(snum, "%d", (int) m_lines.size());
  logThis(snum, target::screen);

  // Needed ?
  while (m_lines.size() > OUTPUT_LINES_MAX)
  {
		logThis("MainScreenSingleton::writeLine ==> scrolling", target::screen);
    scroll2();
  }

  logThis("MainScreenSingleton::writeLine ==> Leaving", target::screen);
}

bool YesNoDialog::execute(const std::string& message)
{

	int maxY, maxX;
	getmaxyx(stdscr, maxY, maxX);

	//TODO: Check message length and that we have enough space !
	WINDOW *dlg = newwin(3, message.size() + 4, (maxY - 3) / 2, (maxX - message.size() - 4) / 2);
	mvwprintw(dlg, 1, 2, message.c_str());
	box(dlg, ACS_VLINE, ACS_HLINE);
	wrefresh(dlg);

	char c;
	do
		c = toupper(getch());
	while (c != 'Y' and c != 'N');

	delwin(dlg);
	return (c == 'Y');
}
