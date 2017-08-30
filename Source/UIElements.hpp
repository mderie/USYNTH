
#ifndef UI_ELEMENTS
#define UI_ELEMENTS

#include <string>
#include <vector>

// If there are multiple screens, just create a base class with "void show();"

class MainScreen
{
private:
	std::vector<std::string> m_lines;
	int m_maxX, m_maxY; // Screen resolution
	void scroll2(); // Care : name clash with curses !
	void clear2(); // Id.
	void show();

public:
	MainScreen();
	~MainScreen();
	void rebuild();
	std::string readLine(char *buffer, int buflen); // Care : blocking call & C style...
	void writeLine(const std::string &s);
};

#endif // UI_ELEMENTS
