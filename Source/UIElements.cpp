
#include <iostream>

// Faking a namespace to avoid name collisions... Doesn't work since curses is full of macros :(
//Neither preceding every cursed stuff by ::
// Maybe should I try this : https://stackoverflow.com/questions/29556093/give-namespace-to-an-existing-library-in-c
//namespace curses
//{
#include <ncurses.h>
//}

// Some C headers that goes with ncurses... And my primitive logger
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "UIElements.hpp"

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

MainScreen::MainScreen()
{
  //toto;
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
  if (m_lines.size() == 0)
  {
    return;
  }

  for (size_t i = 0; i < m_lines.size(); i++)
  {
    m_lines[i] = m_lines[i + 1];
  }

  m_lines.erase(m_lines.end()); //TODO: - 1 ?
}

void MainScreen::clear2()
{
	logThis("MainScreen::clear2 ==> Entering");
  m_lines.clear();
  logThis("MainScreen::clear2 ==> Leaving");
}

void MainScreen::show()
{
	logThis("MainScreen::show ==> Entering");
	if (m_lines.size() == 0)
  {
		logThis("MainScreen::show ==> Leaving : Nothing to do !");
    return;
  }

  int firstLineOffset = 0; // We start at the first line of the buffer
  // Except if we have more lines in the buffer than the screen
  if ((int) m_lines.size() > m_maxY - WASTED_SCREEN_LINES)
  {
    logThis("MainScreen::show ==> Correcting firstLineOffset value");
    firstLineOffset = m_lines.size() - m_maxY + WASTED_SCREEN_LINES;
  }

  char snum[9];
  logThis("MainScreen::show ==> firstLineOffset = ...");
  sprintf(snum, "%d", firstLineOffset);
  logThis(snum);
  logThis("MainScreen::show ==> m_maxY - WASTED_SCREEN_LINES = ...");
  sprintf(snum, "%d", m_maxY - WASTED_SCREEN_LINES);
  logThis(snum);

  for(int i = 1; i < m_maxY - WASTED_SCREEN_LINES + 1; i++)
  {
     logThis("MainScreen::show ==> i + firstLineOffset - 1 = ...");
     sprintf(snum, "%d", i + firstLineOffset - 1);
     logThis(snum);
     logThis("MainScreen::show ==> m_lines[i + firstLineOffset - 1] = ...");
     logThis(m_lines[i + firstLineOffset - 1].c_str());

     mvwprintw(stdscr, i, 1, m_lines[i + firstLineOffset - 1].c_str());

     if ((i + firstLineOffset - 1) == (((int) m_lines.size()) - 1))
     {
				logThis("MainScreen::show ==> Last line displayed");
        break; // We are at the end of our buffer
     }
  }

  logThis("MainScreen::show ==> Leaving");
}

void MainScreen::rebuild()
{
  getmaxyx(stdscr, m_maxY, m_maxX); // Get the screen height & width
  clear(); // We repaint all the screen each time !
	box(stdscr, ACS_VLINE, ACS_HLINE);
	wmove(stdscr, m_maxY - 3, 1);
	hline(ACS_HLINE, m_maxX - 2);
	show();
	mvwprintw(stdscr, m_maxY - 2, 1, "USynth> ");
	refresh();
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
   for (int i = 0; i < len; i++)
   {
      mvaddch(y, x + i, ' ');
   }
   curs_set(old_curs);
	}

	return std::string(buffer);
}

void MainScreen::writeLine(const std::string &s)
{
	logThis("MainScreen::writeLine ==> Entering, s = ...");
	logThis(s.c_str());
  char snum[9];
  sprintf(snum, "%d", (int) m_lines.size());
  logThis(snum);

  m_lines.push_back(s);

  sprintf(snum, "%d", (int) m_lines.size());
  logThis(snum);

  if (m_lines.size() == OUTPUT_LINES_MAX)
  {
     scroll2();
  }

  logThis("MainScreen::writeLine ==> Leaving");
}
