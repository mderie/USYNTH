
#ifndef UI_ELEMENTS
#define UI_ELEMENTS

#include <string>
#include <vector>

// If there are multiple screens, just create a base class with "void show();"

class MainScreenSingleton
{
private:
	static MainScreenSingleton *s_instance;
	std::vector<std::string> m_lines;
	int m_maxX, m_maxY; // Screen resolution
	void scroll2(); // Care : name clash with curses !
	void show();

  MainScreenSingleton();
  MainScreenSingleton(const MainScreenSingleton &) {}

public:
  static MainScreenSingleton *instance(); // We could have use a template Singleton<T>...
	~MainScreenSingleton(); // Unusual (dtor should be private), but we really need to destroy what was allocated inside the ctor :)
	void clear2(); // Id.
	void rebuild();
	std::string readLine(char *buffer, int buflen); // Care : blocking call & C style...
	void writeLine(const std::string &s);
};

class YesNoDialog
{
public:
	static bool execute(const std::string& message);
};

#endif // UI_ELEMENTS
