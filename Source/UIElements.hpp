
#ifndef UI_ELEMENTS
#define UI_ELEMENTS

#include <string>
#include <vector>

// If there are multiple screens, just create a base class with "void show();"

class MainScreen
{
private:
	static MainScreen *s_instance;
	std::vector<std::string> m_lines;
	int m_maxX, m_maxY; // Screen resolution
	void scroll2(); // Care : name clash with curses !
	void show();

  MainScreen();
  MainScreen(const MainScreen&) {}

public:
  static MainScreen* getInstance();
	~MainScreen();
	void clear2(); // Id.
	void rebuild();
	std::string readLine(char *buffer, int buflen); // Care : blocking call & C style...
	void writeLine(const std::string &s);
};

class YesNoDialog
{
	static bool execute(const std::string& message);
};

#endif // UI_ELEMENTS
