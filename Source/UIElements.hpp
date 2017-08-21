
#ifndef UI_ELEMENTS
#define UI_ELEMENTS

#include <string>
#include <vector>
#include <curses.h>

// If there are multiple screens, just create a base class with "void show();"

class MainScreen
{
private:
	std::vector<std::string> lastlines;
	WINDOW *m_mainwin;
	void drawBorders();
public:
	MainScreen() {} // Call show ?
	~MainScreen();
	void show();
	std::string nextCommand(); // Care : blocking call !
	void commandOuput(std::string &s);
};

#endif // UI_ELEMENTS
