
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

MainScreen* MainScreen::s_instance = nullptr;
MainScreen* MainScreen::getInstance()
{
	if (s_instance == nullptr)
	{
		s_instance = new MainScreen();
	}
	return s_instance;
}

MainScreen::MainScreen()
{
  initscr(); // Initialize ncurses
  cbreak(); // No line buffering
  keypad(stdscr, TRUE); // Allow extended key like F1
  curs_set(TRUE); // We want to see the cursor
  noecho(); // We handle the characters output at cursor

  getmaxyx(stdscr, m_maxY, m_maxX);
}

MainScreen::~MainScreen()
{
	endwin();
}

void MainScreen::scroll2()
{
	LOG_THIS("MainScreen::scroll2 ==> Entering");
  if (m_lines.size() == 0)
  {
		LOG_THIS("MainScreen::scroll2 ==> Leaving : Nothing to do !");
    return;
  }

  for (size_t i = 1; i < m_lines.size(); i++)
  {
    m_lines[i - 1] = m_lines[i];
  }

  LOG_THIS("MainScreen::scroll2 ==> Boum next line ?");
  m_lines.erase(m_lines.end());
  LOG_THIS("MainScreen::scroll2 ==> Leaving");
}

void MainScreen::clear2()
{
	LOG_THIS("MainScreen::clear2 ==> Entering");
  m_lines.clear();
  LOG_THIS("MainScreen::clear2 ==> Leaving");
}

void MainScreen::show()
{
	LOG_THIS("MainScreen::show ==> Entering");
	if (m_lines.size() == 0)
  {
		LOG_THIS("MainScreen::show ==> Leaving : Nothing to do !");
    return;
  }

  int firstLineOffset = 0; // We start at the first line of the buffer
  // Except if we have more lines in the buffer than the screen
  if ((int) m_lines.size() > m_maxY - WASTED_SCREEN_LINES)
  {
    LOG_THIS("MainScreen::show ==> Correcting firstLineOffset value");
    firstLineOffset = m_lines.size() - m_maxY + WASTED_SCREEN_LINES;
  }

  char snum[9];
  LOG_THIS("MainScreen::show ==> firstLineOffset = ...");
  sprintf(snum, "%d", firstLineOffset);
  LOG_THIS(snum);
  LOG_THIS("MainScreen::show ==> m_maxY - WASTED_SCREEN_LINES = ...");
  sprintf(snum, "%d", m_maxY - WASTED_SCREEN_LINES);
  LOG_THIS(snum);

  for(int i = 1; i < m_maxY - WASTED_SCREEN_LINES + 1; i++)
  {
     LOG_THIS("MainScreen::show ==> i + firstLineOffset - 1 = ...");
     sprintf(snum, "%d", i + firstLineOffset - 1);
     LOG_THIS(snum);
     LOG_THIS("MainScreen::show ==> m_lines[i + firstLineOffset - 1] = ...");
     LOG_THIS(m_lines[i + firstLineOffset - 1].c_str());

     mvwprintw(stdscr, i, 1, m_lines[i + firstLineOffset - 1].c_str());

     if ((i + firstLineOffset - 1) == (((int) m_lines.size()) - 1))
     {
				LOG_THIS("MainScreen::show ==> Last line displayed");
        break; // We are at the end of our buffer
     }
  }

  LOG_THIS("MainScreen::show ==> Leaving");
}

void MainScreen::rebuild()
{
	LOG_THIS("MainScreen::rebuild ==> Entering");
  getmaxyx(stdscr, m_maxY, m_maxX); // Get the screen height & width
  clear(); // We repaint all the screen each time !
	box(stdscr, ACS_VLINE, ACS_HLINE);
	wmove(stdscr, m_maxY - 3, 1);
	hline(ACS_HLINE, m_maxX - 2);
	show();
	mvwprintw(stdscr, m_maxY - 2, 1, "USynth> ");
	refresh();
	LOG_THIS("MainScreen::rebuild ==> Leaving");
}

std::string MainScreen::readLine(char *buffer, int buflen)
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

void MainScreen::writeLine(const std::string &s)
{
	LOG_THIS("MainScreen::writeLine ==> Entering, s = ...");
	LOG_THIS(s.c_str());
  char snum[9];
  sprintf(snum, "%d", (int) m_lines.size());
  LOG_THIS(snum);

  std::vector<std::string> tokens = split(s, "\n");
  // Yet another lambda :) & means here "this", see :
  // https://stackoverflow.com/questions/4940259/lambdas-require-capturing-this-to-call-static-member-function
  auto push = [&](const std::string& token) { m_lines.push_back(token); LOG_THIS(token.c_str()); };
  std::for_each(tokens.begin(), tokens.end(), push);

  //m_lines.push_back(s);

  sprintf(snum, "%d", (int) m_lines.size());
  LOG_THIS(snum);

  // Needed ?
  while (m_lines.size() > OUTPUT_LINES_MAX)
  {
		LOG_THIS("MainScreen::writeLine ==> scrolling");
    scroll2();
  }

  LOG_THIS("MainScreen::writeLine ==> Leaving");
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
